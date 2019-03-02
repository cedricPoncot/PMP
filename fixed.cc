#include <cstdio>
#include <cstdlib> 
#include <cmath>
#include <iostream>
#include "fixed.h"

namespace fp{
		

		
	
	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	int64_t operator+(fixed <I1, F1> lhs , fixed <I2, F2> rhs){
		int64_t res;
		if(I1>I2){
			if(F1==F2){
				res=lhs.value+rhs.value;
				if(res>fixed_traits<fixed<I1,F1>>::max().value || res<fixed_traits<fixed<I1,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else if(F1>F2){
				res=(rhs.value<<(F1-F2))+lhs.value;
				if(res>fixed_traits<fixed<I1,F1>>::max().value || res<fixed_traits<fixed<I1,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else{
				res=(lhs.value<<(F2-F1))+rhs.value;
				if(res>fixed_traits<fixed<I1,F2>>::max().value || res<fixed_traits<fixed<I1,F2>>::lowest().value){
				
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
		}
		else{
			if(F1==F2){
				res=lhs.value+rhs.value;
				if(res>fixed_traits<fixed<I2,F1>>::max().value || res<fixed_traits<fixed<I2,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else if(F1>F2){
				res=(rhs.value<<(F1-F2))+lhs.value;
				if(res>fixed_traits<fixed<I2,F1>>::max().value || res<fixed_traits<fixed<I2,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else{
				res=(lhs.value<<(F2-F1))+rhs.value;
				//res=0;
				if(res>fixed_traits<fixed<I2,F2>>::max().value || res<fixed_traits<fixed<I2,F2>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
		}
	}
	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	int64_t operator-(fixed <I1, F1> lhs , fixed <I2, F2> rhs){
		int64_t res;
		if(I1>I2){
			if(F1==F2){
				res=lhs.value-rhs.value;
				if(res>fixed_traits<fixed<I1,F1>>::max().value || res<fixed_traits<fixed<I1,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else if(F1>F2){
				res=(rhs.value<<(F1-F2))-lhs.value;
				if(res>fixed_traits<fixed<I1,F1>>::max().value || res<fixed_traits<fixed<I1,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else{
				res=(lhs.value<<(F2-F1))-rhs.value;
				if(res>fixed_traits<fixed<I1,F2>>::max().value || res<fixed_traits<fixed<I1,F2>>::lowest().value){
				
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
		}
		else{
			if(F1==F2){
				res=lhs.value-rhs.value;
				if(res>fixed_traits<fixed<I2,F1>>::max().value || res<fixed_traits<fixed<I2,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else if(F1>F2){
				res=(rhs.value<<(F1-F2))-lhs.value;
				if(res>fixed_traits<fixed<I2,F1>>::max().value || res<fixed_traits<fixed<I2,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else{
				res=(lhs.value<<(F2-F1))-rhs.value;
				if(res>fixed_traits<fixed<I2,F2>>::max().value || res<fixed_traits<fixed<I2,F2>>::lowest().value){
				
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
		}
	}

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	fixed<std::max(I1,I2),std::max(F1,F2)> operator*(fixed <I1, F1> lhs , fixed <I2, F2> rhs){
		return fixed <2,2>(2.0);
		
		fixed<std::max(I1,I2),std::max(F1,F2)>
		/*
		if(I1>I2){
			if(F1==F2){
				res=((lhs.value * rhs.value) >> F1);
				if(res>fixed_traits<fixed<I1,F1>>::max().value || res<fixed_traits<fixed<I1,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else if(F1>F2){
				res=((rhs.value<<(F1-F2))*lhs.value)>>F1;
				if(res>fixed_traits<fixed<I1,F1>>::max().value || res<fixed_traits<fixed<I1,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else{
				res=((lhs.value<<(F2-F1))*rhs.value)>>F2;
				if(res>fixed_traits<fixed<I1,F2>>::max().value || res<fixed_traits<fixed<I1,F2>>::lowest().value){
				
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
		}
		else{
			if(F1==F2){
				res=(lhs.value*rhs.value)>>F1;
				if(res>fixed_traits<fixed<I2,F1>>::max().value || res<fixed_traits<fixed<I2,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else if(F1>F2){
				res=((rhs.value<<(F1-F2))*lhs.value)>>F1;
				if(res>fixed_traits<fixed<I2,F1>>::max().value || res<fixed_traits<fixed<I2,F1>>::lowest().value){
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
			else{
				res=((lhs.value<<(F2-F1))*rhs.value)>>F2;
				if(res>fixed_traits<fixed<I2,F2>>::max().value || res<fixed_traits<fixed<I2,F2>>::lowest().value){
				
					throw std::overflow_error("Debordement de bit");
				}
				return res;
			}
		} */
	}
		
	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator==(fixed <I1 , F1> lhs , fixed <I2 , F2> rhs){
		int64_t res0=lhs.value;
		int64_t res1=rhs.value;
		if(F1==F2){
			return res0==res1;
		}
		else if(F1>F2){
			res1=rhs.value<<(F1-F2);
		}
		else{
			res0=lhs.value<<(F2-F1);
		}
		return res0==res1;
	}
	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator<(fixed <I1, F1> lhs , fixed <I2, F2> rhs){
		int64_t res0=lhs.value;
		int64_t res1=rhs.value;
		if(F1==F2){
			return res0<res1;
		}
		else if(F1>F2){
			res1=rhs.value<<(F1-F2);
		}
		else{
			res0=lhs.value<<(F2-F1);
		}
		return res0<res1;
	}
	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator>(fixed <I1, F1> lhs , fixed <I2, F2> rhs){
		int64_t res0=lhs.value;
		int64_t res1=rhs.value;
		if(F1==F2){
			return res0>res1;
		}
		else if(F1>F2){
			res1=rhs.value<<(F1-F2);
		}
		else{
			res0=lhs.value<<(F2-F1);
		}
		return res0>res1;
	}
	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator<=(fixed <I1, F1> lhs , fixed <I2, F2> rhs){
		int64_t res0=lhs.value;
		int64_t res1=rhs.value;
		if(F1==F2){
			return res0<=res1;
		}
		else if(F1>F2){
			res1=rhs.value<<(F1-F2);
		}
		else{
			res0=lhs.value<<(F2-F1);
		}
		return res0<=res1;
	}
	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator>=(fixed <I1, F1> lhs , fixed <I2, F2> rhs){
		int64_t res0=lhs.value;
		int64_t res1=rhs.value;
		if(F1==F2){
			return res0>=res1;
		}
		else if(F1>F2){
			res1=rhs.value<<(F1-F2);
		}
		else{
			res0=lhs.value<<(F2-F1);
		}
		return res0>=res1;
	}
}









	/*
	* fixed  point  type
	*/
	
	/*template <std::size_t Int , std::size_t  Frac >
	class fixed {
		public:
			using underlying_type = int64_t;
			underlying_type value;
			static  constexpr std::size_t  integer_part = Int;
			static	constexpr std::size_t  fractional_part = Frac;*/


		/*
		* constructors
		*/
		/*fixed() = default;
		constexpr  explicit fixed(float x);
		constexpr  explicit fixed(double x);*/
	
		/*
		* copy  constructors
		*/
		/*fixed(const fixed& other);
		template<std:: size_t  OtherInt , std::size_t  OtherFrac >
		fixed( const fixed <OtherInt , OtherFrac >&  other);*/
	
		/*
		* copy  assignment
		*/
		/*fixed& operator =( const fixed& other);
		template<std::size_t  OtherInt , std::size_t  OtherFrac >
		fixed& operator =( const fixed <OtherInt , OtherFrac >&  other );*/

		/*
		* conversions
		*/
		//operator  float () const;
		//operator  double () const;


		/*
		* compound  assignment  operators
		*/
		/*fixed& operator+=( const fixed& other);
		fixed& operator+=( float other);
		fixed& operator+=( double other);
		template<std::size_t  OtherInt , std::size_t  OtherFrac>
		fixed& operator+=( const fixed <OtherInt , OtherFrac >&  other );
	
		fixed& operator-=( const fixed& other);
		fixed& operator-=( float other);
		fixed& operator-=( double other);
		template<std::size_t  OtherInt , std::size_t  OtherFrac>
		fixed& operator-=( const fixed <OtherInt , OtherFrac >&  other );
	
		fixed& operator*=( const fixed& other);
		fixed& operator*=( float other);
		fixed& operator*=( double other);
		template<std::size_t  OtherInt , std::size_t  OtherFrac>
		fixed& operator*=( const fixed <OtherInt , OtherFrac >&  other );
	
		fixed& operator/=( const fixed& other);
		fixed& operator/=( float other);
		fixed& operator/=( double other);
		template<std::size_t  OtherInt , std::size_t  OtherFrac>
		fixed& operator /=( const fixed <OtherInt , OtherFrac >&  other );*/
	//};


	/*
	* arithmetic  operators
	*/
	/*template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	implementation-defined operator+(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	implementation-defined operator-(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	implementation-defined operator*(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	implementation-defined operator/(fixed <I1, F1> lhs , fixed <I2, F2> rhs)*/


	/*
	* comparison  operators
	*/
	/*template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator==(fixed <I1 , F1> lhs , fixed <I2 , F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator<(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator>(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator<=(fixed <I1 , F1> lhs , fixed <I2 , F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator>=(fixed <I1 , F1> lhs , fixed <I2 , F2> rhs);*/


	/*
	* types
	*/
	/*using Q_8_8 = fixed <8, 8>;
	using Q_16_16 = fixed <16, 16>;
	using Q_0_32 = fixed <0, 32>;*/

	/*
	* traits
	*/
	/*template<typename Fixed>
	struct fixed_traits {
		static  constexpr Fixed  lowest ();
		static  constexpr Fixed  min();
		static  constexpr Fixed  max();
	
		static  constexpr Fixed  zero ();
		static  constexpr Fixed  one();
		static  constexpr Fixed  pi();
	};*/

	/*
	* functions
	*/
	/*template<typename Fixed>
	Fixed sqrt(Fixed f);

	template<typename Fixed>
	std::string to_string(Fixed f);

	template<typename Fixed>
	std::ostream& operator<<(std::ostream& os, Fixed f);*/
//}



















































