#include<bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;
const int N=1e5+7;
struct Complex  {
	double r, i ;
	Complex ( )  {	}
	Complex ( double r, double i ) : r ( r ), i ( i )  {	}
	inline Complex operator + ( const Complex& rhs )  const  {
		return Complex ( r + rhs.r, i + rhs.i ) ;
	}
	inline Complex operator - ( const Complex& rhs )  const  {
		return Complex ( r - rhs.r, i - rhs.i ) ;
	}
	inline Complex operator * ( const Complex& rhs )  const  {
		return Complex ( r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r ) ;
	}
	inline Complex conj ( )  {
		return Complex ( r, -i ) ;
	}
} ;



bool inverse = false ;

inline Complex w ( const int& n, const int& k )  { //w(n,k)
    if ( ! inverse ) return Complex ( cos ( 2 * PI / n * k ), sin ( 2 * PI / n * k ) ) ;
    return Complex ( cos ( 2 * PI / n * k ), sin ( 2 * PI / n * k ) ).conj ( ) ;
}

inline void fft ( Complex *a, const int& n )  {
    if ( n == 1 ) return ;
    static Complex buf [N] ;
    const int m = n / 2  ;
    for ( int i = 0 ; i < m ; ++ i )  {
        buf [i] = a [i * 2 ] ;//次数为偶数
        buf [i + m] = a [i * 2 +1 ] ;//次数为奇数
    }

    memcpy ( a, buf, sizeof ( int ) * ( n + 1 ) ) ;
    Complex *a1 = a, *a2 = a + m;
    fft ( a1, m ) ;//a1为奇数次项
    fft ( a2, m ) ;//a2为偶数次项

    for ( int i = 0 ; i < m ; ++ i )  {
        Complex t = w ( n, i ) ;
        buf [i] = a1 [i] + t * a2 [i] ;
        buf [i + m] = a1 [i] - t * a2 [i] ;
    }
    memcpy ( a, buf, sizeof ( int ) * ( n + 1 ) ) ;
}

int main(){

	return 0;
}
