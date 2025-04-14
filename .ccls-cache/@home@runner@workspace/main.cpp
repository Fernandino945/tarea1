#include <iostream>
#include <vector>
using namespace std;

class pregunta{
protected:
    string enunciado; //Se usara bastante como pregunta
    string respuesta;
    string rc; //Respuesta correcta
public:
    pregunta(string enunciado,string respuesta,string rc){
        this -> enunciado = enunciado;
        this -> respuesta = respuesta;
        this -> rc = rc;
    }
    ~pregunta(){}
    string getEnunciado(){
        return enunciado;
    }
    string getRespuesta(){
        return respuesta;
    }
    string getRc(){
        return rc;
    }
};

class Pcomposicion : public pregunta{ //pregunta de composicion
private:
    string texto;
public:
    Pcomposicion(string texto, string enunciado,string respuesta,string rc) : pregunta(enunciado, respuesta, rc), texto(texto){
        this ->texto = texto;
    }
    ~Pcomposicion(){}
    void mostrarDatos(){
      cout << "\n1. *** Pregunta de composicion *** " << endl;
      cout << "Tema: " << texto << endl;
      cout << "Enunciado: " << enunciado << endl;
      cout << "Respuesta : " << respuesta;
      cin >>  respuesta;
      cout << "La respuesta correcta: " << rc << endl;
    }
};

class Prcorta : public pregunta { //pregunta de respuesta corta
public:
    Prcorta(string enunciado, string respuesta, string rc) : pregunta(enunciado, respuesta, rc){}
    ~Prcorta(){}
    void mostrarDatos(){
        cout << "\n2. *** Pregunta de Respuesta corta ***" << endl;
        cout << "Pregunta.  " << enunciado << endl;
        cout << "Respuesta : " << respuesta;
        cin >> respuesta;
        cout << "La respuesta correcta es "<< rc << endl; 
    }
};

class ptextoin : public pregunta{ //pregunta de texto incompleto
private:
    string oracion;
public:
    ptextoin(string oracion, string enunciado, string respuesta, string rc) : pregunta(enunciado, respuesta, rc), oracion(oracion) {
        this -> oracion = oracion;
    }
    ~ptextoin(){}
    void mostrarDatos(){
        cout << "\n3. *** Pregunta texto incompleto ***" << endl;
        cout << "Tema: " << enunciado << endl;
        cout << "¿Cual es la palabra que falta en la oracion?\n" << oracion << endl;
        cout << "Respuesta: " << respuesta;
        cin >> respuesta;
        cout << "La respuesta correcta: "<< rc << endl;
    }
};

class Pemparejamiento : public pregunta{//pregunta de emparejamiento
private:
    vector <string> colA;
    vector <string> colB;
    string argumento;
public:
    Pemparejamiento(vector<string> colA, vector<string> colB,string argumento,string respuesta, string enunciado,string rc) : pregunta(respuesta,enunciado, rc), colA(colA), colB(colB), argumento(argumento) {
        this -> colA = colA;
        this -> colB = colB;
        this -> argumento = argumento;
    }
    ~Pemparejamiento(){}
    void mostrarDatos(){
        cout << "\n4. *** Pregunta de emparejamiento ***" << endl;
        cout << "Tema: " << enunciado << endl;
        cout << "\n COLUMNA A"<< endl;
        for(size_t i = 0; i < colA.size(); ++i){
            cout << i+1 <<". "<< colA[i]<< endl;
        }
        cout << "\n Columna B" << endl;
        for(size_t i = 0; i < colB.size(); ++i){
            cout << char('a' + i) <<". "<< colB[i]<< endl;
        }
        cout << "Ejemplo de respuesta 1-a, 2-b, 3-c\nRespuesta: " << respuesta;
        cin >> respuesta;
        cout << "Su justificacion: " << argumento ;
        cin >> argumento;
        cout << "La respuesta correcta: "<< rc << endl;
    }
};

class pseleccionm : public pregunta{//pregunta de seleccion multiple
private:
    vector <string> alternativas;
public:
    pseleccionm(vector <string> alternativas, string enunciado,string respuesta,string rc) : pregunta(enunciado, respuesta, rc), alternativas(alternativas) {
        this -> alternativas = alternativas;
    }
    ~pseleccionm(){}
    void mostrarDatos(){
    cout << "\n5. **Pregunta de seleccion multiple ***" << endl;
    cout << "¿En que pais esta varsovia ? " << enunciado << endl;
        for(size_t i=0; i<alternativas.size(); ++i){
            cout << char('a' + i) << ") " <<alternativas[i] << endl;
        }
    cout << "Escoge una alternativa: " << respuesta ;
    cin >> respuesta;
    cout << "La respuesta correcta es: " << rc << endl;
    }
};

class preguntaVF : public pregunta{//pregunta de verdadero o falso
private:
    string justificacion;
    vector <string> VF;
public:
    preguntaVF(string justificacion, vector <string> VF, string enunciado,string respuesta,string rc): pregunta(enunciado, respuesta, rc), justificacion(justificacion), VF(VF) {
        this -> justificacion = justificacion;
        this -> VF = VF;
    }
    ~preguntaVF(){}
    void mostrarDatos(){
        cout << "\n6. ***Pregunta VERDADERO o FALSO justificados ***" << endl;
        cout<< "tema: " << enunciado << endl;
        cout << "Respuesta (v/f): " << respuesta ;
        cin >> respuesta;
        cout <<"Justifique su respuesta: " << justificacion;
        cin >> justificacion;
        cout << "Respuesta es correcta es " << rc << endl;
    }
};

class panaloga : public pregunta{// pregunta de analogia
private:
    vector <string> alternativasB;
public:
    panaloga(vector <string> alternativasB, string enunciado, string respuesta, string rc) : pregunta(enunciado, respuesta, rc), alternativasB(alternativasB){
        this -> alternativasB = alternativasB;
    }
    ~panaloga(){}
    void mostrarDatos(){
        cout << "\n7.***Pregunta de analogias "<< endl;
        cout << "pregunta de animales. " << enunciado << endl;
        for(size_t i=0; i<alternativasB.size(); ++i){
            cout << char('a' + i) << ") " << alternativasB[i] << endl;
        }
        cout << "Respuesta: " << respuesta;
        cin >> respuesta;
        cout << "La respuesta correcta es " << rc << endl;
    }
};

class Pgrafico : public pregunta{ //pregunta de grafico
private:
    vector <string> grafico;
public:
    Pgrafico(vector <string> grafico, string enunciado, string respuesta, string rc) : pregunta(enunciado, respuesta, rc) , grafico(grafico){
        this -> grafico = grafico;
    }
    ~Pgrafico(){}
    void mostrarDatos(){
      cout << "\n8.***Pregunta de grafico ***"<< endl;
      cout << "Se muestran unos graficos de venta de manzanas " << enunciado;
      for(size_t i=0; i<grafico.size(); ++i){
          cout << char('a' + i) << ") " << grafico[i] << endl;
      }
       cout << "Respuesta: " << respuesta;
       cin >> respuesta;
       cout << "La respuesta correcta es " << rc << endl;
    }
};

int main(){
   Pcomposicion p1("Dagron ball","¿Como se llama el protagonista de dragon ball ?", " "," Goku");
   Prcorta p2("¿Capital de venezuela?", " ", "Caracas");
   ptextoin p3(" --La segunda guerra mundialempezo en el año ____ --", "ww2", " ", "1939");
   vector<string> colA = {"Francia", "Chile", "argentina"};
   vector<string> colB = {"santiago", "buenos aires", "paris"};
   Pemparejamiento p4(colA, colB,"", "Capitales del mundo ", " ", "1-c, 2-a, 3-b");
   vector<string> alternativas = {"rusia", "Polonia", "Ucrania"};
   pseleccionm p5(alternativas , " ", " ", "b) polonia");
   vector <string> vf = {"verdadero", "falso"};
   preguntaVF p6("",vf,"El pyro es un personaje de tf2"," ","V");
   vector <string> alternativasB = {"volar", "maulla", "ladrar", "respirar"}; 
   panaloga p7(alternativasB," perro::ladra : gato:: ","","b\nperro::ladra : gato::maulla");
   vector <string> grafico = {"Martin   | ██████\n", "Fernando | ██████████████████\n", "Julio    | ████████████████\n"};
   Pgrafico p8(grafico,"¿Quien vendio mas manzanas?\n", " ", "b" );
   p1.mostrarDatos();
   p2.mostrarDatos();
   p3.mostrarDatos();
   p4.mostrarDatos();
   p5.mostrarDatos();
   p6.mostrarDatos();
   p7. mostrarDatos();
   p8.mostrarDatos();
   return 0;
}