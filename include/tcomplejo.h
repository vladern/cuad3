/* TComplejo.h
 *
 *  Created on: 1 feb. 2017
 *      Author: plakaplaka
 */

#ifndef TCOMPLEJO_H_
#define TCOMPLEJO_H_
#include<iostream>
#include<ostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <ctype.h>
#include <cmath>
using namespace std;
class TComplejo
{
private:
	double re ; // PARTE REAL
	double im ; // PARTE IMAGINARIA
public:
	//pone a zero la parte real y imaginaria
    void clear();
	//Constructor por defecto: PARTE REAL E IMAGINARIA INICIALIZADA A 0
	TComplejo(){re=0,im=0;};
	//Constructor a partir de la PARTE REAL
	TComplejo (double re){this->re=re,im=0;};
	//Constructor a partir de la PARTE REAL e IMAGINARIA
	TComplejo (double re, double im){this->re=re;this->im=im;};
	//Constructor copia
	TComplejo (const TComplejo&);
	//Destructor
	~TComplejo();
	//copia
	void Copia(const TComplejo&);
	// Sobrecarga del operador asignación
	TComplejo& operator= (const TComplejo&);
	// SOBRECARGA DE OPERADORES ARITMÉTICOS;
	TComplejo operator+(const TComplejo&);
	TComplejo operator-(const TComplejo&);
	TComplejo operator*(const TComplejo&);
	TComplejo operator+(double);
	TComplejo operator-(double);
	TComplejo operator*(double);
	//Otros operadores
	bool operator==(const TComplejo&);//IUALDAD de números complejos
	bool operator!=(const TComplejo&);//DESIGUALDAD de números complejos

	double Re()const{return this->re;};//Devuelve parte real
	double Im()const{return this->im;};//Devuelve parte imaginaria

	void Re(double re) {this->re=re;}; // Modifica PARTE REAL
	void Im(double im) {this->im=im;}; // Modifica PARTE IMAGINARIA

	double Arg(void); // Calcula el Argumento (en Radianes)
	double Mod(void)const; // Calcula el Módulo
	
	void negativo(double&,double&);//Convierte el zero negativo(-0.0) a positivo(0.0)si es necesario

	// Sobrecarga del operador SALIDA
	friend ostream & operator<<(ostream &,const TComplejo &);
	friend TComplejo operator+ (double ,const TComplejo&);
	friend TComplejo operator- (double ,const TComplejo&);
	friend TComplejo operator* (double ,const TComplejo&);
	//true si es vacio
	bool EsVacio(){if(this->Re()==0 && this->Im()==0){return true;}return false;}
};
#endif /* TCOMPLEJO_H_ */
