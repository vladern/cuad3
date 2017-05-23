#ifndef TVECTORCOM_H_
#define TVECTORCOM_H_
#include "tcomplejo.h"
#include<stdlib.h>
class TVectorCom
{
    private:
        TComplejo *c; // array de complejos
        int tamano; //el tamaño del array
        TComplejo error;
    public:
        // Constructor por defecto
        TVectorCom();

        // Constructor a partir de un tamaño
        TVectorCom (const int);

        // Constructor de copia
        TVectorCom (const TVectorCom &);

        // Destructor
        ~TVectorCom();

        //copia
        void Copia(const TVectorCom&);

        // Sobrecarga del operador asignación
        TVectorCom & operator=(const TVectorCom &);

        // Sobrecarga del operador igualdad
        bool operator==(const TVectorCom &);
        // Sobrecarga del operador desigualdad
        bool operator!=(const TVectorCom &);
        // Sobrecarga del operador corchete (parte IZQUIERDA)
        TComplejo& operator[](const int);
        // Sobrecarga del operador corchete (parte DERECHA)
        TComplejo operator[](const int) const;
        // Tamaño del vector (posiciones TOTALES)
        int Tamano()const;
        // Cantidad de posiciones OCUPADAS (TComplejo NO VACIO) en el vector
        int Ocupadas()const;
        // Devuelve TRUE si existe el TComplejo en el vector
        bool ExisteCom(const TComplejo &);
        // Mostrar por pantalla los elementos TComplejo del vector con PARTE REAL O POSTERIOR al argumento
        void MostrarComplejos(double);
        // REDIMENSIONAR el vector de TComplejo
        bool Redimensionar(const int);
        // Sobrecarga del operador salida
        friend ostream& operator<<(ostream&,const TVectorCom&);
};
#endif

