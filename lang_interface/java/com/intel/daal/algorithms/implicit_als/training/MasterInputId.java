/* file: MasterInputId.java */
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

package com.intel.daal.algorithms.implicit_als.training;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__IMPLICIT_ALS__TRAINING__MASTERINPUTID"></a>
 * @brief Available identifiers of input objects for the implicit ALS training algorithm
 * in the second step of the distributed processing mode
 */
public final class MasterInputId {
    private int _value;

    static {
        System.loadLibrary("JavaAPI");
    }

    /**
     * Constructs the input object identifier using the provided__value
     * @param value     Value of the input object identifier
     */
    public MasterInputId(int value) {
        _value = value;
    }

    /**
     * Returns the value of the input object identifier
     * @return Value of the input object identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int inputOfStep2FromStep1Id = 0;

    /** %Input data table */
    public static final MasterInputId inputOfStep2FromStep1 = new MasterInputId(inputOfStep2FromStep1Id);
    /*!< DataCollection containing data transferred from the first step to the second step of the distributed processing mode */
}
