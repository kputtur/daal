/* file: em_gmm_init.h */
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
//  Implementation of the EM for GMM initialization interface.
//--
*/

#ifndef __EM_INIT_
#define __EM_INIT_

#include "em_gmm_init_types.h"

namespace daal
{
namespace algorithms
{
namespace em_gmm
{
namespace init
{

/**
 * Allocates memory for storing initial values for results of the EM for GMM algorithm
 * \param[in] input        Pointer to the input structure
 * \param[in] parameter    Pointer to the parameter structure
 * \param[in] method       Method of the algorithm
 */
template <typename algorithmFPType>
DAAL_EXPORT void Result::allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method)
{
    Input *algInput = static_cast<Input *>(const_cast<daal::algorithms::Input *>(input));
    Parameter *algParameter = static_cast<Parameter *>(const_cast<daal::algorithms::Parameter *>(parameter));

    size_t nFeatures   = algInput->get(data)->getNumberOfColumns();
    size_t nComponents = algParameter->nComponents;

    Argument::set(weights, data_management::SerializationIfacePtr(new data_management::HomogenNumericTable<algorithmFPType>(nComponents, 1,
                  data_management::NumericTable::doAllocate, 0)));
    Argument::set(means, data_management::SerializationIfacePtr(new data_management::HomogenNumericTable<algorithmFPType>(
                      nFeatures, nComponents, data_management::NumericTable::doAllocate, 0)));

    data_management::DataCollectionPtr covarianceCollection =
        data_management::DataCollectionPtr(new data_management::DataCollection());
    for(size_t i = 0; i < nComponents; i++)
    {
        if(algParameter->covarianceStorage == em_gmm::diagonal)
        {
            covarianceCollection->push_back(data_management::NumericTablePtr(
                                                new data_management::HomogenNumericTable<algorithmFPType>(
                                                    nFeatures, 1, data_management::NumericTable::doAllocate, 0)));
        }
        else
        {
            covarianceCollection->push_back(data_management::NumericTablePtr(
                                                new data_management::HomogenNumericTable<algorithmFPType>(
                                                    nFeatures, nFeatures, data_management::NumericTable::doAllocate, 0)));
        }
    }
    Argument::set(covariances, services::staticPointerCast<SerializationIface, data_management::DataCollection>(covarianceCollection));
}

} // namespace init
} // namespace em_gmm
} // namespace algorithms
} // namespace daal

#endif
