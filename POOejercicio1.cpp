#include <iostream>
#include <conio.h>
#include<limits>
#include <locale.h>
#include <cstdlib>

using namespace std;
// Estructura para almacenar información de n alumnos
struct Alumno{
    string nombre;
    int edad;
    float promedio;
};

int main(){
    setlocale(LC_ALL,"Spanish");
    
    int registro,pos=0,pos2=0;
    float menor=numeric_limits<float>::max();
    float suma=0,media=0,mayor=0;
    bool estado=false;
    
    while(estado!=true){
    	system("cls");
        cout<<"Numero de alumnos a registrar: ";
        cin>>registro;
        
        if(registro>0 && registro<10000){
           estado=true; 
        }else{
        	cout<<"El número ingresado no es válido. Intente nuevamente.\n\n";
        	system("pause");
		}
        cout<<endl;
    } 
    cin.ignore();
    
    Alumno alumnos[registro];
    // Pedir los datos de los alumnos
    for (int i=0;i<registro;i++){
        cout<<"Nombre: ";
        getline(cin,alumnos[i].nombre);
        cout<<"Edad: ";
        cin>>alumnos[i].edad;
        cout<<"Promedio: ";
        cin>>alumnos[i].promedio; 
        
        suma+=alumnos[i].promedio;
        
        if(alumnos[i].promedio>mayor){
            mayor=alumnos[i].promedio;
            pos=i;
        }
        
        if(menor>alumnos[i].promedio){
            menor=alumnos[i].promedio;
            pos2=i;
        }  
        cout<<"\n";
        cin.ignore();
    }
    system("cls");
    media=suma/registro;
    
    if(registro>1){
    	cout<<"\n------------------------------\n";
	    cout<<"\nAlumno con mejor promedio: \n";
	    cout<<"Nombre: "<<alumnos[pos].nombre<<endl;
	    cout<<"Edad: "<<alumnos[pos].edad<<endl;
	    cout<<"Promedio: "<<alumnos[pos].promedio<<endl;
	    
	    cout<<"\n------------------------------\n";
	    cout<<"\nAlumno con el menor promedio: \n";
	    cout<<"Nombre: "<<alumnos[pos2].nombre<<endl;
	    cout<<"Edad: "<<alumnos[pos2].edad<<endl;
	    cout<<"Promedio: "<<alumnos[pos2].promedio<<endl;
	    
	    cout<<"\n------------------------------\n";
	    cout<<"\nPromedio de clase: \n\n";
	    cout<<media;
		  
	}else if(registro==1){
		cout<<"\n------------------------------\n";
	    cout<<"\nDatos del estudiante: \n";
	    cout<<"Nombre: "<<alumnos[pos].nombre<<endl;
	    cout<<"Edad: "<<alumnos[pos].edad<<endl;
	    cout<<"Promedio: "<<alumnos[pos].promedio<<endl;
	    
	    cout<<"El promedio de clase, es el promedio del único estudiante.\n";
	} 
}
