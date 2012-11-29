/***************************************************************************       
*   Copyright 2012 Advanced Micro Devices, Inc.                                     
*                                                                                    
*   Licensed under the Apache License, Version 2.0 (the "License");   
*   you may not use this file except in compliance with the License.                 
*   You may obtain a copy of the License at                                          
*                                                                                    
*       http://www.apache.org/licenses/LICENSE-2.0                      
*                                                                                    
*   Unless required by applicable law or agreed to in writing, software              
*   distributed under the License is distributed on an "AS IS" BASIS,              
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.         
*   See the License for the specific language governing permissions and              
*   limitations under the License.                                                   

***************************************************************************/
#pragma once
#if !defined( CONSTANT_ITERATOR_H )
#define CONSTANT_ITERATOR_H
#include "bolt/cl/bolt.h"

namespace bolt
{
    namespace cl
    {
        BOLT_TEMPLATE_FUNCTOR3( constant_iterator, int, float, double,
            template< typename T >
            class constant_iterator
            {
                typedef size_t difference_type;
                typedef size_t size_type;
                typedef T value_type;
                typedef T* pointer;
                typedef T& reference;
                typedef std::random_access_iterator_tag iterator_category;

                value_type  constValue;

            public:
                constant_iterator( value_type init ): constValue( init )
                {};

                value_type operator[]( size_type )
                {
                    return constValue;
                }

                value_type operator*( )
                {
                    return constValue;
                }

            };
        )

        template< typename Type >
        constant_iterator< Type > make_constant_iterator( Type constValue )
        {
            return constant_iterator< Type > tmp( constValue );
        }
    }
}

#endif