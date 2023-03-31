#include <iostream>
using namespace std;
const char *nombre_archivo= "archivo.dat";
struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float promedio;
};
void ejercicio1(){
	
	int cant;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cant;

    int id[cant];
    string nombres[cant], apellidos[cant];
    float notas[cant][4], promedio[cant];

    for (int i = 0; i < cant; i++) {
        cout << "Ingrese los datos del estudiante #" << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id[i];
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, nombres[i]);
        cout << "Apellidos: ";
        getline(cin, apellidos[i]);
        for (int j = 0; j < 4; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> notas[i][j];
        }
        promedio[i] = (notas[i][0] + notas[i][1] + notas[i][2] + notas[i][3]) / 4;
        cout << endl;
    }

    for (int i = 0; i < cant; i++) {
        cout << "Estudiante #" << i + 1 << endl;
        cout << "ID: " << id[i] << endl;
        cout << "Nombres: " << nombres[i] << endl;
        cout << "Apellidos: " << apellidos[i] << endl;
        cout << "Promedio: " << promedio[i] << endl;
        if (promedio[i] >= 60) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
        cout << endl;
    }	
	
}
void ejercicio2(){
	
  	int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    
    Estudiante* estudiantes = new Estudiante[n];
    
    for (int i = 0; i < n; i++) {
        Estudiante* estudiante = &estudiantes[i];
        cout << "Ingrese los datos del estudiante " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiante->id;
        cout << "Nombres: ";
        cin >> estudiante->nombres;
        cout << "Apellidos: ";
        cin >> estudiante->apellidos;
        cout << "Nota 1: ";
        cin >> estudiante->nota1;
        cout << "Nota 2: ";
        cin >> estudiante->nota2;
        cout << "Nota 3: ";
        cin >> estudiante->nota3;
        cout << "Nota 4: ";
        cin >> estudiante->nota4;
		
		//promedio
		float suma = estudiante->nota1 + estudiante->nota2 + estudiante->nota3 + estudiante->nota4;
		estudiante->promedio = suma / 4.0;
		
		//comprobacion Estado
		if (estudiante->promedio >= 60.0) {
        cout << "El estudiante " << estudiante->nombres << " " << estudiante->apellidos << " ha aprobado con un promedio de " << estudiante->promedio << endl;
   		 } else {
        cout << "El estudiante " << estudiante->nombres << " " << estudiante->apellidos << " ha reprobado con un promedio de " << estudiante->promedio << endl;
    	}
		
		cout<<"\n";
        
    }
    delete[] estudiantes;
    
};

void ejercicio3(){
	char opcion;
	int n,i=0;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    Estudiante* estudiantes = new Estudiante[n];
    do{
		Estudiante* estudiante = &estudiantes[i];
        cout << "Ingrese los datos del estudiante " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiante->id;
        cout << "Nombres: ";
        cin >> estudiante->nombres;
        cout << "Apellidos: ";
        cin >> estudiante->apellidos;
        cout << "Nota 1: ";
        cin >> estudiante->nota1;
        cout << "Nota 2: ";
        cin >> estudiante->nota2;
        cout << "Nota 3: ";
        cin >> estudiante->nota3;
        cout << "Nota 4: ";
        cin >> estudiante->nota4;
		
		//promedio
		float suma = estudiante->nota1 + estudiante->nota2 + estudiante->nota3 + estudiante->nota4;
		estudiante->promedio = suma / 4.0;
		
		//comprobacion Estado
		if (estudiante->promedio >= 60.0) {
        	cout << "El estudiante " << estudiante->nombres << " " << estudiante->apellidos << " ha aprobado con un promedio de " << estudiante->promedio << endl;
    	} else {
        	cout << "El estudiante " << estudiante->nombres << " " << estudiante->apellidos << " ha reprobado con un promedio de " << estudiante->promedio << endl;
    	}
		
		cout<<"Quiere ingresar otro alumno (S/N)"<<endl;
		cin>>opcion;
		cout<<"\n";
		i++;
    }while((opcion=='S' ||opcion=='s') && i < n);
    
	char confirmar;
	cout<<"Ingresa (S/s) para guardar la informacion: "<<endl;
	cin>>confirmar;
   if(confirmar=='S' || confirmar=='s'){
   	 FILE*archivo=fopen(nombre_archivo,"a+b");
    fwrite(estudiantes,sizeof(Estudiante),i,archivo);
    fclose(archivo);
    delete[] estudiantes;
   }
};

void leer(){
    FILE* archivo = fopen(nombre_archivo,"rb");
    if(!archivo){
        archivo = fopen(nombre_archivo,"w+b");
        fclose(archivo);
        archivo = fopen(nombre_archivo,"rb");
    }
    Estudiante estudiantes;
    cout << "==========================================" << endl;
    cout << "ID" << "|" << "NOMBRES" << "|" << "APELLIDOS" << "|" << "NOTA1" << "|" << "NOTA2" << "|" << "NOTA3" << "|" << "NOTA4" << endl;
    while(fread(&estudiantes,sizeof(Estudiante),1,archivo) == 1){
        cout << estudiantes.id << "|" << estudiantes.nombres << "|" << estudiantes.apellidos << "|" << estudiantes.nota1 << "|" << estudiantes.nota2 << "|" << estudiantes.nota3 << "|" << estudiantes.nota4 << endl;
    }
    fclose(archivo);
}
int main(){

	//ejercicio1();
	//ejercicio2();
	//ejercicio3();
	leer();
};
