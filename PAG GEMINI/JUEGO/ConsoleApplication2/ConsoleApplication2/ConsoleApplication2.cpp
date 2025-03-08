#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

// Función para escribir con efecto de máquina de escribir
void delayText(const string& text, int delayMs = 50) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}

// Función para generar un número aleatorio
int obtenerNumeroAleatorio(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

// Preguntas y respuestas
vector<pair<string, string>> preguntasYRespuestas = {
    {"Que pais es famoso por su carne asada?", "Argentina"},
    {"De que color es el sol?", "Amarillo"},
    {"Cual es la bebida mas popular en Mexico?", "Tequila"},
    {"Cuantos planetas hay en el sistema solar?", "8"},
    {"Quien fue Albert Einstein?", "Un fisico teorico"},
    {"Cuantas patas tiene un gato?", "4"},
    {"Como se llama el hermano de Mario?", "Luigi"},
    {"Que animal tiene una trompa?", "Elefante"},
    {"Cuantos colores tiene el arco iris?", "7"},
    {"En que pais se encuentra la Torre Eiffel?", "Francia"},
};

// Frases para respuestas incorrectas
vector<string> respuestasIncorrectas = {
    "Seguro que no estas jugando en serio?",
    "Estas seguro de lo que dices? No es la respuesta correcta.",
    "Ay no! Se nota que no estudiaste antes de jugar.",
    "Parece que te equivocaste. Pero no te preocupes, todos cometemos errores.",
    "No es la respuesta correcta. Pero en el intento demostraste algo, no?",
    "Te falta un poco mas de concentracion. No pasa nada, todos cometemos errores.",
    "Y esa respuesta? Vamos, que no es la correcta. Deberias practicar mas.",
    "De verdad creiste que eso era correcto? Vuelve a intentarlo.",
    "JAJAJA... muy lejos de la respuesta correcta.",
    "Pues... no. Pero en fin, sigue intentandolo.",
};

// Respuestas variadas a "Por que sigues aqui?"
vector<string> respuestasPorQueSigues = {
    "Bueno, supongo que no tienes nada mejor que hacer, verdad?",
    "En serio? Todavia quieres continuar? Esto no tiene sentido.",
    "Porque te aburriste tanto que estas dispuesto a seguir aqui. Interesante.",
    "Lo unico que puedo pensar es que no tienes nada mejor que hacer.",
    "Mucha gente se iria, pero tu eres un caso especial.",
    "Tu sigues ahi! Que estas buscando? La verdad absoluta?",
    "Si esperas que esto se ponga mas interesante, siento decirte que no lo hara.",
    "Porque no tienes vida social, cierto?",
    "Sigues aqui porque no hay otro lugar a donde ir, supongo.",
    "Porque claramente, no te rindes facilmente.",
};

// Variables para el conteo de respuestas
int respuestasCorrectas = 0;
int respuestasIncorrectasContadas = 0;

int main() {
    string nombre;

    // Mensaje de bienvenida
    delayText("Bienvenido al Desafio de la Maquina...");
    delayText("Cual es tu nombre, humano? (O si prefieres, puedes dejarme adivinarlo... sera algo basico como Juan?)");
    getline(cin, nombre);

    if (nombre == "Juan") {
        delayText("Adivine tu nombre! No es como si fuera dificil, verdad? XD");
    }

    delayText("Vaya... un nuevo desafiante... Que original...");
    delayText("Veamos si eres digno de mis invaluables desafios... aunque dudo que lo seas.");

    bool continuar = true;
    while (continuar) {
        // Elegir una pregunta aleatoria
        int indice = obtenerNumeroAleatorio(0, preguntasYRespuestas.size() - 1);
        pair<string, string> pregunta = preguntasYRespuestas[indice];

        delayText(pregunta.first);

        string respuesta;
        getline(cin, respuesta);

        // Verificar si la respuesta es correcta
        if (respuesta == pregunta.second) {
            delayText("Respuesta correcta!: " + pregunta.second);
            respuestasCorrectas++;
        }
        else {
            int indexIncorrecta = obtenerNumeroAleatorio(0, respuestasIncorrectas.size() - 1);
            delayText(respuestasIncorrectas[indexIncorrecta]);
            respuestasIncorrectasContadas++;
        }

        delayText("Aun quieres seguir respondiendo? (s/n)");
        string seguir;
        getline(cin, seguir);

        if (seguir == "n" || seguir == "N") {
            delayText("Has decidido irte... Sorprendente, no esperaba tanto.");
            continuar = false;
        }
        else {
            int indexSigue = obtenerNumeroAleatorio(0, respuestasPorQueSigues.size() - 1);
            delayText(respuestasPorQueSigues[indexSigue]);
        }
    }

    // Mostrar el resumen de respuestas al final
    delayText("Resumen de tu desempeno:");
    delayText("Respuestas correctas: " + to_string(respuestasCorrectas));
    delayText("Respuestas incorrectas: " + to_string(respuestasIncorrectasContadas));

    // Guardar los puntajes en un archivo
    ofstream archivo("puntajes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Usuario: " << nombre << endl;
        archivo << "Respuestas correctas: " << respuestasCorrectas << endl;
        archivo << "Respuestas incorrectas: " << respuestasIncorrectasContadas << endl;
        archivo << "--------------------------------" << endl;
        archivo.close();
    }
    else {
        cout << "Error al abrir el archivo de puntajes." << endl;
    }

    return 0;
}
