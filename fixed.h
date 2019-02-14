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
	/*
	* fixed  point  type
	*/
	
	template <std::size_t Int , std::size_t  Frac >
	class fixed {
		public:
			using underlying_type = int64_t;
			underlying_type value;
			static  constexpr std::size_t  integer_part = Int;
			static	constexpr std::size_t  fractional_part = Frac;


		/*
		* constructors
		*/
		fixed()=default;
		constexpr  explicit fixed(float x){
			//static_assert(Int+Frac<=64&&Int+Frac>0,"Erreur");
			size_t n=Int+Frac;
			if (x<-std::exp2(n-1)/n || (x>std::exp2(n-1)-1)/n) {
				throw std::overflow_error("Debordement de bit");
			}
			value=x*std::exp2(fractional_part);
		}
		constexpr  explicit fixed(double x){
			//static_assert(Int+Frac<=64&&Int+Frac>0,"Erreur");
			if ((int)x>std::exp2(integer_part-1)-1) {
				throw std::overflow_error("Debordement de bit");
			}
			value=x*std::exp2(fractional_part);
		}
	
		/*
		* copy  constructors
		*/
		fixed(const fixed& other){
			value=other.value;
		}
		template <std::size_t OtherInt,std::size_t OtherFrac >
		fixed(const fixed <OtherInt , OtherFrac >& other){
			if(fractional_part==OtherFrac)value=other.value;
			if(fractional_part>OtherFrac){
				value=other.value<<(fractional_part-OtherFrac);
			}
			else{
				value=other.value>>(OtherFrac-fractional_part);
			}
		}
	
		/*
		* copy  assignment
		*/
		fixed& operator=(const fixed& other){
			this->value=other.value;
			return *this;
		}
		template <std:: size_t  OtherInt , std:: size_t  OtherFrac >
		fixed& operator=(const fixed <OtherInt , OtherFrac >&  other ){
			if(fractional_part==OtherFrac)this.value=other.value;
			if(fractional_part>OtherFrac){
				this.value=other.value<<(fractional_part-OtherFrac);
			}
			else{
				this.value=other.value>>(OtherFrac-fractional_part);
			}
			return *this;
		}

		/*
		* conversions
		*/
		operator double() const{
			return (double)value/std::exp2(fractional_part);
		}
		operator float() const{
			return (float)value/std::exp2(fractional_part);
		}


		/*
		* compound  assignment  operators
		*/
		fixed& operator+=( const fixed& other){
			this->value=*this+other;
			return *this;
		}
		fixed& operator+=( float other){
			this->value=*this+fixed(other);
			return *this;
		}
		fixed& operator+=( double other){
			this->value=*this+fixed(other);
			return *this;
		}
		template<std::size_t  OtherInt , std::size_t  OtherFrac>
		fixed& operator+=( const fixed <OtherInt , OtherFrac >&  other ){
			this->value=*this+other;
			return *this;
		}
	
		fixed& operator-=( const fixed& other){
			this->value=*this-other;
			return *this;
		}
		fixed& operator-=( float other){
			this->value=*this-fixed(other);
			return *this;
		}
		fixed& operator-=( double other){
			this->value=*this-fixed(other);
			return *this;
		}
		template<std::size_t  OtherInt , std::size_t  OtherFrac>
		fixed& operator-=( const fixed <OtherInt , OtherFrac >&  other ){
			this->value=*this+other;
			return *this;
		}
	
		fixed& operator*=( const fixed& other);
		fixed& operator*=( float other);
		fixed& operator*=( double other);
		template<std::size_t  OtherInt , std::size_t  OtherFrac>
		fixed& operator*=( const fixed <OtherInt , OtherFrac >&  other );
	
		fixed& operator/=( const fixed& other);
		fixed& operator/=( float other);
		fixed& operator/=( double other);
		template<std::size_t  OtherInt , std::size_t  OtherFrac>
		fixed& operator /=( const fixed <OtherInt , OtherFrac >&  other );
	};


	/*
	* arithmetic  operators
	*/
	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	int64_t operator+(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	int64_t operator-(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	int64_t operator*(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	int64_t operator/(fixed <I1, F1> lhs , fixed <I2, F2> rhs);


	/*
	* comparison  operators
	*/
	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator==(fixed <I1 , F1> lhs , fixed <I2 , F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator<(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator>(fixed <I1, F1> lhs , fixed <I2, F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator<=(fixed <I1 , F1> lhs , fixed <I2 , F2> rhs);

	template<std::size_t I1, std::size_t F1, std::size_t I2, std::size_t F2>
	bool  operator>=(fixed <I1 , F1> lhs , fixed <I2 , F2> rhs);


	/*
	* types
	*/
	using Q_8_8 = fixed <8, 8>;
	using Q_16_16 = fixed <16, 16>;
	using Q_0_32 = fixed <0, 32>;

	/*
	* traits
	*/
	template <typename Fixed>  //fixed_traits<...>::max()
		struct fixed_traits{
			static constexpr Fixed lowest(){
				fixed <Fixed::integer_part,Fixed::fractional_part>f(0.0);
				size_t n=Fixed::integer_part+Fixed::fractional_part;
				f.value=-(2<<(n-2));
				return f;
			}
			static constexpr Fixed min(){
				fixed <Fixed::integer_part,Fixed::fractional_part>f(0.0);
				f.value=1;
				return f;
			}
			static constexpr Fixed max(){
				fixed <Fixed::integer_part,Fixed::fractional_part>f(0.0);
				size_t n=Fixed::integer_part+Fixed::fractional_part;
				f.value=(2<<(n-2))-1;
				return f;
			}
		};

	/*
	* functions
	*/
	template<typename Fixed>
	Fixed sqrt(Fixed f);

	template<typename Fixed>
	std::string to_string(Fixed f);

	template<typename Fixed>
	std::ostream& operator<<(std::ostream& os, Fixed f);


} // namespace fp

#endif // FIXED_H
