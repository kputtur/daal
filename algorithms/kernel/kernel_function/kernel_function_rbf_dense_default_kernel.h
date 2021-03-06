/* file: kernel_function_rbf_dense_default_kernel.h */
/*******************************************************************************
* Copyright 2014-2016 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Declaration of template structs that calculate SVM RBF Kernel functions.
//--
*/

#ifndef __KERNEL_FUNCTION_RBF_DENSE_DEFAULT_KERNEL_H__
#define __KERNEL_FUNCTION_RBF_DENSE_DEFAULT_KERNEL_H__

#include "kernel_function_dense_base.h"
#include "kernel_function_rbf_base.h"

using namespace daal::internal;

namespace daal
{
namespace algorithms
{
namespace kernel_function
{
namespace rbf
{
namespace internal
{

template <typename algorithmFPType, CpuType cpu>
struct KernelImplRBF<defaultDense, algorithmFPType, cpu> :
    public daal::algorithms::kernel_function::internal::KernelImplBase<algorithmFPType, cpu>
{
    using daal::algorithms::kernel_function::internal::KernelImplBase<algorithmFPType, cpu>::prepareDataVectorVector;
    using daal::algorithms::kernel_function::internal::KernelImplBase<algorithmFPType, cpu>::prepareDataMatrixVector;
    using daal::algorithms::kernel_function::internal::KernelImplBase<algorithmFPType, cpu>::prepareDataMatrixMatrix;
    virtual void computeInternal(size_t nFeatures, size_t nVectors1, const algorithmFPType *dataA1,
                                 size_t nVectors2, const algorithmFPType *dataA2,
                                 algorithmFPType *dataR, const ParameterBase *par, bool inputTablesSame);

    virtual void prepareData(BlockMicroTable<algorithmFPType, readOnly,  cpu> &mtA1,
                             BlockMicroTable<algorithmFPType, readOnly,  cpu> &mtA2,
                             BlockMicroTable<algorithmFPType, writeOnly, cpu> &mtR,
                             const ParameterBase *svmPar,
                             size_t *nVectors1, algorithmFPType **dataA1,  size_t *nVectors2, algorithmFPType **dataA2,
                             algorithmFPType **dataR, bool inputTablesSame);

    void computeInternalVectorVector(
        size_t nFeatures, size_t nVectors1, const algorithmFPType *dataA1,
        size_t nVectors2, const algorithmFPType *dataA2,
        algorithmFPType *dataR, const ParameterBase *par);

    void computeInternalMatrixVector(
        size_t nFeatures, size_t nVectors1, const algorithmFPType *dataA1,
        size_t nVectors2, const algorithmFPType *dataA2,
        algorithmFPType *dataR, const ParameterBase *par);

    void computeInternalMatrixMatrix(
        size_t nFeatures, size_t nVectors1, const algorithmFPType *dataA1,
        size_t nVectors2, const algorithmFPType *dataA2,
        algorithmFPType *dataR, const ParameterBase *par, bool inputTablesSame);
};

} // namespace internal

} // namespace rbf

} // namespace kernel_function

} // namespace algorithms

} // namespace daal

#endif
