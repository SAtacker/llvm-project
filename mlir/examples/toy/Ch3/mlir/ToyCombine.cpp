//===- ToyCombine.cpp - Toy High Level Optimizer --------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements a set of simple combiners for optimizing operations in
// the Toy dialect.
//
//===----------------------------------------------------------------------===//

#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/IR/Value.h"
#include "mlir/Support/LogicalResult.h"
#include "toy/Dialect.h"
using namespace mlir;
using namespace toy;

namespace {
/// Include the patterns defined in the Declarative Rewrite framework.
#include "ToyCombine.inc"
} // namespace

/// This is an example of a c++ rewrite pattern for the TransposeOp. It
/// optimizes the following scenario: transpose(transpose(x)) -> x
struct SimplifyRedundantTranspose : public mlir::OpRewritePattern<TransposeOp> {
  /// We register this pattern to match every toy.transpose in the IR.
  /// The "benefit" is used by the framework to order the patterns and process
  /// them in order of profitability.
  SimplifyRedundantTranspose(mlir::MLIRContext *context)
      : OpRewritePattern<TransposeOp>(context, /*benefit=*/1) {}

  /// This method attempts to match a pattern and rewrite it. The rewriter
  /// argument is the orchestrator of the sequence of rewrites. The pattern is
  /// expected to interact with it to perform any changes to the IR from here.
  mlir::LogicalResult
  matchAndRewrite(TransposeOp op,
                  mlir::PatternRewriter &rewriter) const override {
    // Look through the input of the current transpose.
    mlir::Value transposeInput = op.getOperand();
    TransposeOp transposeInputOp = transposeInput.getDefiningOp<TransposeOp>();

    // Input defined by another transpose? If not, no match.
    if (!transposeInputOp)
      return failure();

    // Otherwise, we have a redundant transpose. Use the rewriter.
    rewriter.replaceOp(op, {transposeInputOp.getOperand()});
    return success();
  }
};

//===----------------------------------------------------------------------===//
// SimplifyRedundantMatMul
//===----------------------------------------------------------------------===//

struct SimplifyRedundantMatMul : public OpRewritePattern<MulOp> {
  SimplifyRedundantMatMul(mlir::MLIRContext *context)
      : OpRewritePattern<MulOp>(context, /*benefit=*/1) {}

  mlir::LogicalResult
  matchAndRewrite(MulOp op, mlir::PatternRewriter &rewriter) const override {
    // Look through the input of the current matmul.
    mlir::Value matmulInput1 = op.getOperand(0);
    mlir::Value matmulInput2 = op.getOperand(1);
    MulOp matmulInputOp = matmulInput1.getDefiningOp<MulOp>();
    MulOp matmulInputOp2 = matmulInput2.getDefiningOp<MulOp>();

    // Input defined by another matmul? If not, no match.
    if (!matmulInputOp)
      return failure();
    if (!matmulInputOp2)
      return failure();

    // Otherwise, we have a redundant matmul. Use the rewriter.
    rewriter.replaceOpWithNewOp<MulOp>(op, op.getType(),
                                          matmulInputOp.getOperand(0),
                                          op.getOperand(0));
    rewriter.replaceOpWithNewOp<MulOp>(op, op.getType(),
                                          matmulInputOp.getOperand(1),
                                          op.getOperand(1));
    return success();
  }
};

/// Register our patterns as "canonicalization" patterns on the MulOp so
/// that they can be picked up by the Canonicalization framework.
void MulOp::getCanonicalizationPatterns(RewritePatternSet &results,
                                              MLIRContext *context) {
  results.add<SimplifyRedundantMatMul>(context);
}

/// Register our patterns as "canonicalization" patterns on the TransposeOp so
/// that they can be picked up by the Canonicalization framework.
void TransposeOp::getCanonicalizationPatterns(RewritePatternSet &results,
                                              MLIRContext *context) {
  results.add<SimplifyRedundantTranspose>(context);
}

/// Register our patterns as "canonicalization" patterns on the ReshapeOp so
/// that they can be picked up by the Canonicalization framework.
void ReshapeOp::getCanonicalizationPatterns(RewritePatternSet &results,
                                            MLIRContext *context) {
  results.add<ReshapeReshapeOptPattern, RedundantReshapeOptPattern,
              FoldConstantReshapeOptPattern>(context);
}
