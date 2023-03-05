# json-simple
Es una biblioteca C++ fácil de usar para leer y escribir archivos y cadenas de texto JSON. Esta biblioteca es ideal para aquellos que buscan una forma rápida y sencilla de trabajar con JSON, y es adecuada tanto para proyectos grandes como pequeños. Tiene las funciones necesarias ni mas ni menos.

### Estandar JSON
- El utilzado el standar json y su extructura de su pagina principal:
https://www.json.org/json-en.html

### Creado por:
- <font color="gree">Daniel</font>
<font color="red">Andino</font>
Camacho
- hello1234dan@gmail.com

### Importar lib.

```cpp
#include "json-simple/json.h"
```

### Leer String json

```cpp
JsonRead jread;

JsonData dat = jread.load(
  "{\n"
  "  \"name\": \"Daniel\", \n"
  "  \"age\": 18 \n"
  "}"
);

JSONObject objMain(&dat); 

//Accede a la key name
//Forma mas corta de recuperar datos
cout << objMain["name"].STR << endl;

//Otra forma de recuperar los datos

cout << objMain.getString("name") << endl;
```

- Leer array []

```cpp
JsonRead jread;

JsonData dat = jread.load(
  "[\n"
  "  \"Daniel\", \n"
  "  18 \n"
  "]"
);

JSONArray arrMain(&dat); 

//Accede a la key name
//Forma mas corta de recuperar datos

cout << arrMain[0].STR << endl;

//Otra forma de recuperar los datos

cout << arrMain.getString(0) << endl;
```

### Leer File json

```cpp
JsonRead jread;
JsonData dat = jread.loadFile("nameFile.json");

JSONObject objMain(&dat); 

//Accede a la key name
//Forma mas corta de recuperar datos

cout << objMain["name"].STR << endl;

//Otra forma de recuperar los datos

cout << objMain.getString("name") << endl;
```

### Documentacion

#### `Clases utilizables por el usuario.`

- JsonRead
- JsonWrite
- JSObject
- JSArray
- JSONObject
- JSONArray
- JSONValues

### `JsonRead`

Descripción: Esta clase se utiliza para parsear un string o archivo a una estructura de datos que represente es json `JsonData`.

## Sintaxis
```cpp
class JsonRead {
  private:
    JsonData dat;
  public:
    JsonData load(string jsonString);
    JsonData loadFile(string filename);
};

```

### `load(std::string jsonString)`
Esta función convierte `jsonString` en un objeto `JsonData` como una estructura que representa el json. 

### Parámetros:
- `jsonString`: Json en formato string "{}".

### Retorno:
- Objeto de la clase `JsonData`.

### Ejemplo:
```c++
string jsonText = "{\n"
"   \"name\":\"Nombre\" \n"
"}";
JsonRead jread;
JsonData dat = jread.load(jsonText);
```

---

### `loadFile(std::string filename)`
Esta función lee el archivo en la ruta `filename` y lo convierte en un objeto `JsonData` como una estructura que representa el json file. 

### Parámetros:
- `filename`: Ruta del archivo json a analizar y parsear.

### Retorno:
- Objeto de la clase `JsonData`.

### Ejemplo:
```c++
string path = "./file.json";
JsonRead jread;
JsonData dat = jread.loadFile(path);
```

### `JsonWrite`

Descripción: Esta clase se utiliza para crear archivos `.json`.

## Sintaxis
```cpp
class JsonWrite{
  private:
    void writeFile(string jsonText, string nameFile);
  public:
    void write(JSObject ob, string nameFile);
    void write(JSArray ar, string nameFile);
};

```

### `write(JSObject ob, std::string nameFile)`
Esta función crea un archivo json apartir de un Objeto de la clase JSObject. 

### Parámetros:
- `ob`: Objeto de la clase JSObject.
- `nameFile`: Ruta y nombre del archivo a crear `.json`.

### Retorno:
- No retorna nada `void`.

### Ejemplo:
```cpp
JSObject job;
job.add("name", "Daniel");
//job == {"name": "Daniel"}
string nameFile = "./file.json";
JsonWrite().write(job, nameFile);
```

---

### `write(JSArray ar, std::string nameFile)`
Esta función crea un archivo json apartir de un Objeto de la clase JSArray.

### Parámetros:
- `ar`: Objeto de la clase JSArray.
- `nameFile`: Ruta y nombre del archivo a crear `.json`.

### Retorno:
- No retorna nada `void`.

### Ejemplo:
```cpp
JSArray jar;
jar.add((string)"Hola");
jar.add((string)"Mundo");
//jar == ["Hola", "Mundo"]
string nameFile = "./file.json";
JsonWrite().write(jar, nameFile);
```

### `JSObject`

Descripción: Esta clase se utiliza para crear Objeto json para utilizar en la clase JsonWrite.

## Sintaxis
```cpp
class JSObject{
  private:
    void addValue(string key, string value);
    string elements;
  public:
    void add(string key, string value);
    void add(string key, int value);
    void add(string key, float value);
    void add(string key, bool value);
    void add(string key, JSObject value);
    void add(string key, JSArray value);
    string toString();
    JSObject();
    JSObject(string key, string value);
    JSObject(string key, int value);
    JSObject(string key, float value);
    JSObject(string key, bool value);
    JSObject(string key, JSObject value);
    JSObject(string key, JSArray value);
};

```

### `add(std::string key, value)`
Esta función agrega un nuevo conjunto `"clave"`: `"valor"` al objeto instancia de la clase creado.

### Parámetros:
- `key`: String del con el nombre de la key a crear. ejemplo `"name"`.
- `value`: El parametro value puede cambiar puede ser value de tipo:
  - String ejemplo `"key": "Hola"`.
  - Int ejemplo `"key": 32`.
  - Float ejemplo `"key": 32.5`.
  - Boolean ejemplo `"key": true`.
  - Objeto ejemplo `"key": {}` donde {} viene siendo un objeto de la clase JSObject.
  - Arreglo ejemplo `"key": []` donde [] viene siendo un objeto de la clase JSArray.

### Retorno:
- No retorna nada `void`.

### Ejemplo:
```cpp
//Creando instancia a clase JSObject
JSObject job;
//String
job.add("str", "value");
//Int
job.add("int", (int) 10);
//Float
job.add("float", (float) 10.13);
//Boolean
job.add("bool", true);
//Object
job.add("obj", JSObject("n", "str"));
//Array
JSObject jarr;
jarr.add("hola"); //[0] = "hola"
job.add("arr", jarr);
```

---

### `toString()`
Retorna todo el JSObject creado pero como string

### Retorno:
- Retorna std::string.

### Ejemplo:
```cpp
JSObject job;
job.add("name", "Daniel");
//job_str == "{\"name\": \"Daniel\"}"
string job_str = job.toString();
```

---

### `JSObject(std::string key, value)`
Constructor de la clase con las mismas caracteristicas de las funciones add.

### Ejemplo:
```cpp
//String
JSObject job("str", "value");
//Int
JSObject job("int", (int) 10);
//Float
JSObject job("float", (float) 10.13);
//Boolean
JSObject job("bool", true);
//Object
JSObject job("obj", JSObject("n", "str"));
//Array
JSArray jarr;
jarr.add("hola"); //[0] = "hola"
JSObject job("arr", jarr);
```

### `JSArray`

Descripción: Esta clase se utiliza para crear Array json para utilizar en la clase JsonWrite.

## Sintaxis
```cpp
class JSArray{
  private:
    void addValue(string value);
    string elements;
  public:
    void add(string value);
    void add(int value);
    void add(float value);
    void add(bool value);
    void add(JSObject value);
    void add(JSArray value);
    string toString();
    JSArray();
    JSArray(string value);
    JSArray(int value);
    JSArray(float value);
    JSArray(bool value);
    JSArray(JSObject value);
};

```

### `add(value)`
Esta función agrega una nueva posicion de array con el valor pasado como `value` en la instancia de la clase creada.

### Parámetros:
- `value`: El parametro value puede cambiar puede ser value de tipo:
  - String ejemplo `"key": "Hola"`.
  - Int ejemplo `"key": 32`.
  - Float ejemplo `"key": 32.5`.
  - Boolean ejemplo `"key": true`.
  - Objeto ejemplo `"key": {}` donde {} viene siendo un objeto de la clase JSObject.

### Retorno:
- No retorna nada `void`.

### Ejemplo:
```cpp
//Creando instancia a clase JSArray
JSArray jarr;
//String
jarr.add("value");
//Int
jarr.add((int) 10);
//Float
jarr.add((float) 10.13);
//Boolean
jarr.add(true);
//Object
jarr.add(JSObject("n", "str"));
//Array
JSArray jarr1;
jarr1.add("hola"); //[0] = "hola"
jarr.add(jarr1);
```

---

### `toString()`
Retorna todo el JSArray creado pero como string

### Retorno:
- Retorna std::string.

### Ejemplo:
```cpp
JSArray jarr;
jarr.add("Daniel");
//jarr_str == "[\"Daniel\"]"
string jarr_str = jarr.toString();
```

---

### `JSObject(value)`
Constructor de la clase con las mismas caracteristicas de las funciones add.

### Ejemplo:
```cpp
//String
JSArray jarr("value");
//Int
JSArray jarr((int) 10);
//Float
JSArray jarr((float) 10.13);
//Boolean
JSArray jarr(true);
//Object
JSArray jarr(JSObject("n", "str"));
```

### `JSONObject`
Descripción: Esta clase se utiliza para crear un Objeto para utilizar en la lectura de un correspondiente a la clase `JsonRead`.

## Sintaxis
```cpp
class JSONObject{
  public:
    string id;
    JsonData *dat;
    
    //Read values
    JSONValues operator[](string key);
    string getString(string key);
    int getInt(string key);
    float getFloat(string key);
    bool getBool(string key);
    JSONObject getObject(string key);
    JSONArray getArray(string key);

    JSONObject(JsonData *data);
    JSONObject();

};

```

### `operator[](std::string key)`
Esta función recupera el valor `value` de un conjunto key: `value`.

### Parámetros:
- `key`: Llave `string` para acceder al valor `value`.

### Retorno:
- Retorna un objeto de tipo JSONValues.

### Ejemplo:
```cpp
string jsonText = "{\n"
"   \"name\":\"Nombre\" \n"
"}";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONObject objMain(&dat);
objMain["name"]; // return object JSONValues

```

---

### `getString(std::string key)`
Esta función recupera el valor `value` de un conjunto key: `value` como un string.

### Parámetros:
- `key`: Llave `string` para acceder al valor `value`.

### Retorno:
- Retorna el `value` como string.

### Ejemplo:
```cpp
string jsonText = "{\n"
"   \"name\":\"Nombre\" \n"
"}";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONObject objMain(&dat);

// srt_name == "Nombre"
string str_name = objMain.getString("name");

```

---

### `getInt(std::string key)`
Esta función es exactamente igual que getString() pero solo devuelve como `int`.

### Ejemplo:
```cpp
string jsonText = "{\n"
"   \"num\": 45 \n"
"}";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONObject objMain(&dat);

// num == 45
int num = objMain.getInt("num");

```

---

### `getFloat(std::string key)`
Esta función es exactamente igual que getString() pero solo devuelve como `float`.

### Ejemplo:
```cpp
string jsonText = "{\n"
"   \"num\": 4.6 \n"
"}";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONObject objMain(&dat);

// num == 4.6
float num = objMain.getFloat("num");

```

---

### `getBool(std::string key)`
Esta función es exactamente igual que getString() pero solo devuelve como `bool`.

### Ejemplo:
```cpp
string jsonText = "{\n"
"   \"state\": true \n"
"}";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONObject objMain(&dat);

// state == true == 1
bool state = objMain.getBool("state");

```

---

### `getObject(std::string key)`
Esta función es exactamente igual que getString() pero solo devuelve como `JSONObject`.

### Ejemplo:
```cpp
string jsonText = "{\n"
"   \"object\": { \n"
"     \"saludo\": \"Hi!\" \n"
"   } \n"
"}";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONObject objMain(&dat);

// jb == {"saludo": "Hi!"}
JSONObject jb = objMain.getObject("object");

// sal == "Hi!"
string sal = jb.getString("saludo");

```

---

### `getArray(std::string key)`
Esta función es exactamente igual que getString() pero solo devuelve como `JSONArray`.

### Ejemplo:
```cpp
string jsonText = "{\n"
"   \"array\": [ \n"
"     \"Hola!\", \"Hi!\" \n"
"   ] \n"
"}";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONObject objMain(&dat);

// jrr == ["Hola!", "Hi!"]
JSONArray jrr = objMain.getArray("array");

```

---

### `JSONObject(JsonData *dat)`
Este es el constructor de la clase que recibe un objeto puntero (la direccion de memoria `&`) de tipo `JsonData` el cual contine el json en cierta estructura.

### Ejemplo:
```cpp
string jsonText = "{\n"
"   \"hi\": \"Hola\" \n"
"}";

JsonRead jread;
JsonData dat = jread.load(jsonText);

//&dat es un puntero al object `dat`
JSONObject objMain(&dat);
```

### `JSONArray`
Descripción: Esta clase se utiliza para crear un Array para utilizar en la lectura de un correspondiente a la clase `JsonRead`.

## Sintaxis
```cpp
class JSONArray{
  public:
    string id;
    JsonData *dat;

    //Read values
    JSONValues operator[](int pos);
    string getString(int pos);
    int getInt(int pos);
    float getFloat(int pos);
    bool getBool(int pos);
    JSONObject getObject(int pos);
    JSONArray getArray(int pos);

    //Length del array
    int length();

    JSONArray(JsonData *data);
    JSONArray();

};
```

### `operator[](int pos)`
Esta función recupera el valor `value` de la posicion pasada `pos`.

### Parámetros:
- `pos`: Posicion `int` para acceder al valor `value` de la posicion.

### Retorno:
- Retorna un objeto de tipo JSONValues.

### Ejemplo:
```cpp
string jsonText = "[\n"
"   \"Name\", \"Nombre\" \n"
"]";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONArray arrMain(&dat);
arrMain[0]; // return object JSONValues

```

---

### `getString(int pos)`
Esta función recupera el valor `value` de la posicion pasada `pos` como un string.

### Parámetros:
- `pos`: Posicion `int` para acceder al valor `value` de la posicion.

### Retorno:
- Retorna el `value` como string.

### Ejemplo:
```cpp
string jsonText = "[\n"
"   \"Name\", \"Nombre\" \n"
"]";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONArray arrMain(&dat);

// srt_name == "Nombre"
string str_name = arrMain.getString(1);

```

---

### `getInt(int pos)`
Esta función es exactamente igual que getString() pero solo devuelve como `int`.

### Ejemplo:
```cpp
string jsonText = "[\n"
"   45, 90, 34 \n"
"]";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONArray arrMain(&dat);

// num == 45
int num = arrMain.getInt(0);

```

---

### `getFloat(int pos)`
Esta función es exactamente igual que getString() pero solo devuelve como `float`.

### Ejemplo:
```cpp
string jsonText = "[\n"
"   4.6, 4.3, 3.2 \n"
"]";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONArray arrMain(&dat);

// num == 4.6
float num = arrMain.getFloat(0);

```

---

### `getBool(std::string key)`
Esta función es exactamente igual que getString() pero solo devuelve como `bool`.

### Ejemplo:
```cpp
string jsonText = "[\n"
"   true, false \n"
"]";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONArray arrMain(&dat);

// state == true == 1
bool state = arrMain.getBool(0);

```

---

### `getObject(std::string key)`
Esta función es exactamente igual que getString() pero solo devuelve como `JSONObject`.

### Ejemplo:
```cpp
string jsonText = "[\n"
"   { \n"
"     \"saludo\": \"Hi!\" \n"
"   } \n"
"]";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONArray arrMain(&dat);

// jb == {"saludo": "Hi!"}
JSONObject jb = arrMain.getObject(0);

// sal == "Hi!"
string sal = jb.getString("saludo");

```

---

### `getArray(std::string key)`
Esta función es exactamente igual que getString() pero solo devuelve como `JSONArray`.

### Ejemplo:
```cpp
string jsonText = "[\n"
"   [ \n"
"     \"Hola!\", \"Hi!\" \n"
"   ] \n"
"]";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONArray arrMain(&dat);

// jrr == ["Hola!", "Hi!"]
JSONArray jrr = arrMain.getArray(0);

```

---

### `length()`
Esta función es para saber el tamano de un array object `JSONArray`.

### Retorno
- Retorna int como length del JSONArray.

### Ejemplo:
```cpp
string jsonText = "[\n"
"   [ \n"
"     \"Hola!\", \"Hi!\" \n"
"   ] \n"
"]";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONArray arrMain(&dat);
//len == 1
int len = arrMain.length();
```

---

### `JSONArray(JsonData *dat)`
Este es el constructor de la clase que recibe un objeto puntero (la direccion de memoria `&`) de tipo `JsonData` el cual contine el json en cierta estructura.

### Ejemplo:
```cpp
string jsonText = "[\n"
"   \"hi\", \"Hola\" \n"
"]";

JsonRead jread;
JsonData dat = jread.load(jsonText);

//&dat es un puntero al object `dat`
JSONArray arrMain(&dat);
```

### `JSONValues`
Descripción: Esta clase se utiliza para crear una forma mas corta de leer `JSONObject` y `JSONArray`.

## Sintaxis
```cpp
class JSONValues{
  public:
    string STR;
    int INT;
    float FLO;
    bool BOO;
    JSONObject OBJ;
    JSONArray ARR;
};
```

### Ejemplos:
```cpp
string jsonText = "[\n"
"   \"name\": \"Daniel\", \n"
"   \"value\": 93, \n"
"   \"b\": true, \n"
"   \"f\": 5.2, \n"
"   \"obj\": {\"h\": \"Hi!\"}"
"   \"arr\": [ \n"
"     \"Hola!\", \"Hi!\" \n"
"   ] \n"
"}";

JsonRead jread;
JsonData dat = jread.load(jsonText);

JSONObject objMain(&dat);

//Para acceder ejemplo a `name` hay dos maneras ya es preferencia del user usar una o otra

//Manera `larga` visto de cierta manera
objMain.getString("name");

//Manera `corta`
//Lo que devuelve objMain["name"] en un object tipo JSONValues
//Y despues se accede a su propiedad STR que contiene el valor como string

objMain["name"].STR; //string

//Y haci lo mismo con los otros tipos de datos
//Todos los ejemplos `cortos`

objMain["name"].STR; //string
objMain["value"].INT; //int
objMain["b"].BOO; //boolean
objMain["f"].FLO; //float
objMain["obj"].OBJ; //JSONObject
objMain["arr"].ARR; //JSONArray

//Todos los ejemplos `largos``

objMain.getString("name"); //string
objMain.getInt("value"); //int
objMain.getBool("b"); //boolean
objMain.getFloat("f"); //float
objMain.getObject("obj"); //JSONObject
objMain.getArray("arr"); //JSONArray

```

### `Importante`
La forma corta de acceder a los datos solo funciona al sobrecargar el operator `[]` o lo que es lo mismo al decir ejemplo `objMain["key"].`

---

### `Licencia`
La Licencia esta en el archivo `LICENSE.txt` <a href="LICENSE.txt">Ver <'o></a>.