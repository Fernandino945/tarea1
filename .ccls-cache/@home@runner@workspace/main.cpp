#include <iostream>
#include <vector>
using namespace std;

const string NIVELES_BLOOM[] = { // * Se utiliza para clasificar el tipo de pensamiento requerido por las preguntas.
    "Recordar", "Entender", "Aplicar", "Analizar", "Evaluar", "Crear"
};

class pregunta {
protected:
    string enunciado;//Se usara bastante como pregunta
    string respuesta;
    string rc; // Respuesta correcta
    string nivelBloom;
public:
    pregunta(string enunciado, string respuesta, string rc, string nivelBloom = "Recordar") {
        this->enunciado = enunciado;
        this->respuesta = respuesta;
        this->rc = rc;
        this->nivelBloom = nivelBloom;
    }
   ~pregunta(){}
    string getEnunciado() const {
        return enunciado;
    }
    string getRespuesta() const {
        return respuesta;
    }
    string getRc() const {
        return rc;
    }
    string getNivelBloom() const {
        return nivelBloom;
    }
};

class Pcomposicion : public pregunta {//pregunta de composicion
private:
    string texto;
public:
    Pcomposicion(string texto, string enunciado, string respuesta, string rc, string nivelBloom = "Crear") 
        : pregunta(enunciado, respuesta, rc, nivelBloom), texto(texto) {
          this -> texto = texto;
        }
    void mostrarDatos(){
        cout << "\n1. *** Pregunta de composicion *** " << endl;
        cout << "Nivel Bloom: " << getNivelBloom() << endl;
        cout << "Tema: " << texto << endl;
        cout << "Enunciado: " << getEnunciado() << endl;
        cout << "Respuesta: ";
        cin >> respuesta;
        cout << "La respuesta correcta: " << getRc() << endl;
    }
};

class Prcorta : public pregunta {
public:
    Prcorta(string enunciado, string respuesta, string rc, string nivelBloom = "Recordar") : pregunta(enunciado, respuesta, rc, nivelBloom) {}
    void mostrarDatos(){
        cout << "\n2. *** Pregunta de Respuesta corta ***" << endl;
        cout << "Nivel Bloom: " << getNivelBloom() << endl;
        cout << "Pregunta: " << getEnunciado() << endl;
        cout << "Respuesta: ";
        cin >> respuesta;
        cout << "La respuesta correcta es " << getRc() << endl; 
    }
};

class ptextoin : public pregunta { //pregunta de texto incompleto
private:
    string oracion;
public:
    ptextoin(string oracion, string enunciado, string respuesta, string rc, string nivelBloom = "Recordar") : pregunta(enunciado, respuesta, rc, nivelBloom), oracion(oracion) {
       this -> oracion = oracion;
    }
    void mostrarDatos(){
        cout << "\n3. *** Pregunta texto incompleto ***" << endl;
        cout << "Nivel Bloom: " << getNivelBloom() << endl;
        cout << "Tema: " << getEnunciado() << endl;
        cout << "¿Cual es la palabra que falta en la oracion?\n" << oracion << endl;
        cout << "Respuesta: ";
        cin >> respuesta;
        cout << "La respuesta correcta: "<< getRc() << endl;
    }
};

class Pemparejamiento : public pregunta { //pregunta de emparejamiento
private:
    vector<string> colA;
    vector<string> colB;
    string argumento;
public:
Pemparejamiento(vector<string> colA, vector<string> colB, string argumento, string enunciado, string rc, string nivelBloom = "Analizar") : pregunta(enunciado, "", rc, nivelBloom), colA(colA), colB(colB), argumento(argumento){
   this -> colA = colA;
   this -> colB = colB;
   this -> argumento = argumento;
}
    void mostrarDatos(){
        cout << "\n4. *** Pregunta de emparejamiento ***" << endl;
        cout << "Nivel Bloom: " << getNivelBloom() << endl;
        cout << "Tema: " << getEnunciado() << endl;
        cout << "\nCOLUMNA A"<< endl;
        for(size_t i = 0; i < colA.size(); ++i) {
            cout << i+1 << ". "<< colA[i] << endl;
        }
        cout << "\nCOLUMNA B" << endl;
        for(size_t i = 0; i < colB.size(); ++i) {
            cout << char('a' + i) << ". "<< colB[i] << endl;
        }
        cout << "Ejemplo de respuesta: 1-a, 2-b, 3-c\nRespuesta: ";
        cin >> respuesta;
        cout << "Su justificacion: ";
        cin.ignore(); // Limpiar buffer antes de getline
        getline(cin, argumento);
        cout << "La respuesta correcta: "<< getRc() << endl;
    }
};

class pseleccionm : public pregunta { //pregunta de seleccion multiple
private:
    vector<string> alternativas;
public:
    pseleccionm(vector<string> alternativas, string enunciado, string rc, string nivelBloom = "Recordar") 
        : pregunta(enunciado, "", rc, nivelBloom), alternativas(alternativas) {
          this -> alternativas = alternativas;
        }
    void mostrarDatos(){
        cout << "\n5. *** Pregunta de seleccion multiple ***" << endl;
        cout << "Nivel Bloom: " << getNivelBloom() << endl;
        cout << "Pregunta: " << getEnunciado() << endl;
        for(size_t i = 0; i < alternativas.size(); ++i) {
            cout << char('a' + i) << ") " << alternativas[i] << endl;
        }
        cout << "Escoge una alternativa: ";
        cin >> respuesta;
        cout << "La respuesta correcta es: " << getRc() << endl;
    }
};

class preguntaVF : public pregunta { //pregunta de verdadero o falso
private:
    string justificacion;
public:
    preguntaVF(string justificacion,string enunciado, string rc, string nivelBloom = "Evaluar") : pregunta(enunciado, "", rc, nivelBloom) {
      this -> justificacion = justificacion;
    }
    void mostrarDatos(){
        cout << "\n6. *** Pregunta VERDADERO o FALSO justificada ***" << endl;
        cout << "Nivel Bloom: " << getNivelBloom() << endl;
        cout << "pregunta: " << getEnunciado() << endl;
        cout << "Respuesta (v/f): ";
        cin >> respuesta;
        cout << "Justifique su respuesta: ";
        cin.ignore();
        getline(cin, justificacion);
        cout << "La respuesta correcta es " << getRc() << endl;
    }
};

class panaloga : public pregunta { //pregunta de analogia
private:
    vector<string> alternativasB;
public:
    panaloga(vector<string> alternativasB, string enunciado, string rc, string nivelBloom = "Analizar")  : pregunta(enunciado, "", rc, nivelBloom), alternativasB(alternativasB) {
      this -> alternativasB = alternativasB;
    }
    void mostrarDatos(){
        cout << "\n7. *** Pregunta de analogias ***" << endl;
        cout << "Nivel Bloom: " << getNivelBloom() << endl;
        cout << "Pregunta: " << getEnunciado() << endl;
        for(size_t i = 0; i < alternativasB.size(); ++i) {
            cout << char('a' + i) << ") " << alternativasB[i] << endl;
        }
        cout << "Respuesta: ";
        cin >> respuesta;
        cout << "La respuesta correcta es " << getRc() << endl;
    }
};

class Pgrafico : public pregunta { //pregunta de grafico
private:
    vector<string> grafico;
public:
    Pgrafico(vector<string> grafico, string enunciado, string rc, string nivelBloom = "Evaluar") : pregunta(enunciado, "", rc, nivelBloom), grafico(grafico) {
      this -> grafico = grafico;
    }
    void mostrarDatos(){
        cout << "\n8. *** Pregunta de grafico ***" << endl;
        cout << "Nivel Bloom: " << getNivelBloom() << endl;
        cout << "Pregunta: " << getEnunciado() << endl;
        for(size_t i = 0; i < grafico.size(); ++i) {
            cout << grafico[i];
        }
        cout << "Respuesta: ";
        cin >> respuesta;
        cout << "La respuesta correcta es " << getRc() << endl;
    }
};

int main() {
    Pcomposicion p1("Dragon ball", "¿Como se llama el protagonista de dragon ball?", "", "Goku", "Recordar");
    Prcorta p2("¿Capital de Venezuela?", "", "Caracas", "Recordar");
    ptextoin p3("--La segunda guerra mundial empezo en el año ____ --", "Historia", "", "1939", "Recordar");
    vector<string> colA = {"Francia", "Chile", "Argentina"};
    vector<string> colB = {"Santiago", "Buenos Aires", "Paris"};
    Pemparejamiento p4(colA, colB, "", "Relaciona cada capital con su pais", "1-c, 2-a, 3-b", "Analizar");
    vector<string> alternativas = {"Rusia", "Polonia", "Ucrania"};
    pseleccionm p5(alternativas, "¿En qué país está Varsovia?", "b) Polonia", "Recordar");
    preguntaVF p6("Comics", "Batman es un personaje de dc comics", "V");
    vector<string> alternativasB = {"volar", "maulla", "ladrar", "respirar"}; 
    panaloga p7(alternativasB, "perro::ladra : gato::", "b) maulla", "Analizar");
    vector<string> grafico = {
        "Martin   | ██████ 6 \n", 
        "Fernando | ██████████████████ 22\n", 
        "Julio    | ████████████████18\n"
    };
    Pgrafico p8(grafico, "¿Quien vendio más manzanas?", "b", "Evaluar");
    // Mostrar preguntas en pantalla
    p1.mostrarDatos();
    p2.mostrarDatos();
    p3.mostrarDatos();
    p4.mostrarDatos();
    p5.mostrarDatos();
    p6.mostrarDatos();
    p7.mostrarDatos();
    p8.mostrarDatos();

    return 0;
}