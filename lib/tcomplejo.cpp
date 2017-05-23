/* TComplejo.h
 *
 *  Created on: 1 feb. 2017
 *      Author: plakaplaka
 */
 #include"tcomplejo.h"

 //pone a zero la parte real y imaginaria
void TComplejo::clear()
{
	Re(0);
	Im(0);
}
//Constructor de copia
 TComplejo::TComplejo(const TComplejo& num)
 {   
        this->Copia(num);
 }
 TComplejo::~TComplejo()
 {
     this->re=0;
     this->im=0;
 }
 void TComplejo::negativo(double &re,double &im)
 {
     if(re==(-0.0) && im==(-0.0))
     {
         re=0.0;
     }else if(im==(-0.0))
     {
         im=0.0;
     }else if(re==(-0.0))
     {
         re=0.0;
     }
 }
void TComplejo::Copia(const TComplejo& num)
{
        this->re=num.re;
        this->im=num.im;
}
// Sobrecarga del operador asignación
TComplejo& TComplejo::operator = (const TComplejo& num)
{
    if(this != &num)
    {
        //lo destruyo
        this->~TComplejo();
        // y lo copio
        this->Copia(num);
    }
    return *this;
}
// SOBRECARGA DE OPERADORES ARITMÉTICOS;
TComplejo TComplejo::operator+(const TComplejo& num)
{
    TComplejo nuevo; // objeto auxiliar
    nuevo.im = this->im+num.im;
    nuevo.re = this->re+num.re;
    return nuevo;
}
TComplejo TComplejo::operator-(const TComplejo& num)
{
    TComplejo nuevo; // objeto auxiliar
    nuevo.im = this->im-num.Im();
    nuevo.re = this->re-num.Re();
    return nuevo;
}
TComplejo TComplejo::operator*(const TComplejo& num)
{
    //(a+bi)*(c+di)=(ac-bd)+(ad+bc)i
    double re = (this->Re()*num.Re())-(this->Im()*num.Im());
    double im = ((this->Re()*num.Im())+(this->Im()*num.Re()));
    TComplejo nuevo(re,im);
    return nuevo;
}
TComplejo TComplejo::operator+(double num)
{
    if(num==(-0.0))
    {
        num=0.0;
    }
    double re = this->re + num;
    double im = this->im + 0;
    TComplejo nuevo(re,im);
    return nuevo;
}
TComplejo TComplejo::operator-(double num)
{
    if(num==(-0.0))
    {
        num=0.0;
    }
    double re = this->re - num;
    double im = this->im - 0;
    TComplejo nuevo(re,im);
    return nuevo;
}
TComplejo TComplejo::operator*(double num)
{
    if(num==(-0.0))
    {
        num=0.0;
    }
    //(a+bi)*(c+di)=(ac-bd)+(ad+bc)i
    double re = this->Re()*num;
    double im = 0;
    TComplejo nuevo(re,im);
    return nuevo;
}
    //IUALDAD de números complejos
	bool TComplejo::operator==(const TComplejo& num)
    {
        if(this->re==num.re && this->im==num.im)
        {
            return true;
        }
        return false;
    }
    //DESIGUALDAD de números complejos
	bool TComplejo::operator!=(const TComplejo& num)
    {
        return !((*this)==num);
    }
    // Calcula el Argumento (en Radianes)
	double TComplejo::Arg(void)
    {
        return atan2(this->im,this->re);
    } 
    // Calcula el Módulo 
	double TComplejo::Mod(void)const
    {
       return sqrt(pow(this->re,2)+pow(im,2));
    }
    
    ostream& operator<<(ostream &os,const TComplejo &num)
    {
        os<<"("<<num.Re()<<" "<<num.Im()<<")";
        return os;
    }
/*    TComplejo operator+ (double re,const TComplejo& num)//como el re no es TComplejo hay que  hacer  lo amigo
    {
        TComplejo nuevo(this+num);
        return nuevo;
    }
	TComplejo operator-(double re,const TComplejo& num)
    {
        TComplejo nuevo(this->Re()-num.Re(),0-num.Im());
        return nuevo;
    }
	TComplejo operator* (double re,const TComplejo& num)
    {
        TComplejo nuevo(this->Re()*num.Re());
        return nuevo;
    }*/
