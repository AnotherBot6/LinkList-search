template <typename T> class Persona {
private:
  T id, first_name, last_name,zip ,city;
public:
  Persona(T id = "", T fname = "", T lname = "",T zip = "", T city = "") {
    this->id = id;
    this->zip = zip;
    this->first_name = fname;
    this->last_name = lname;
    this->city = city;
  }
  T getFirstName(){
    return first_name;
  }
  void SetPersona(T id, T fname, T lname,T zip, T city) {
    this->id = id;
    this->zip = zip;
    this->first_name = fname;
    this->last_name = lname;
    this->city = city;
  }

  /*
  Agrega las sobre cargas de operadores necesarias en la clase Persona.
  */
  T getlname() {
  return last_name;
  }
  T getpersona() {
  T a = id+" "+first_name+" "+last_name+" "+zip+" "+city;
  return a;
  }
  T getCity(){
    return city;
  }
};
