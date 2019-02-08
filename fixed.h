#ifndef FIXED_H
#define FIXED_H

#include <cstddef>
#include <cstdio>
#include <cstdlib> 
#include <cmath>
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <type_traits>

namespace fp {
	template<std::size_t Int , std::size_t  Frac >
	class fixed {	
		public:
		using underlying_type =int64_t;
		underlying_type value;
		static  constexpr std::size_t  integer_part = Int;
		static  constexpr std::size_t  fractional_part = Frac;
		fixed()=default;
		constexpr  explicit fixed(float x){
			//static_assert(Int+Frac<=64,"Erreur");
			size_t n=Int+Frac;
			if (x<-std::exp2(n-1)/n || (x>std::exp2(n-1)-1)/n) {
				throw std::overflow_error("Debordement de bit");
			}
			value=x*std::exp2(fractional_part);
		}
		constexpr  explicit fixed(double x){
			//static_assert(Int+Frac<=64,"Erreur");
			if ((int)x>std::exp2(integer_part-1)-1) {
				throw std::overflow_error("Debordement de bit");
			}
			value=x*std::exp2(fractional_part);
		}
		
		
		operator double() const{
			return (double)value/std::exp2(fractional_part);
		}
		operator float() const{
			return (float)value/std::exp2(fractional_part);
		}
		/*
		* copy  constructors
		*/
		fixed(const fixed& other){
			value=other.value;
		}
		
	};
	template<std:: size_t I1, std:: size_t F1, std:: size_t I2, std:: size_t F2>
	int64_t operator+(fixed <I1, F1> lhs , fixed <I2, F2> rhs){
		int64_t res=0;

		std::cout<<"Passage";
		if(F1==F2)return lhs+rhs;
		std::cout<<"Passage";
		if(F1>F2){
			res+=rhs.value<<(F1-F2);
		}
		else{
			res+=lhs.value<<(F2-F1);
		}
		return lhs+rhs;
	}
	
	template <typename Fixed>  //fixed_traits<...>::max()
		struct fixed_traits{
			static constexpr Fixed lowest(){
				fixed <Fixed::integer_part,Fixed::fractional_part>f();
				size_t n=Fixed::integer_part+Fixed::fractional_part;
				f.value=-(2<<(n-1));
				return f;
			}
			static constexpr Fixed max(){

			}
		};



} // namespace fp

#endif // FIXED_H
