class Task{
  private:
    string id;
    int value;
  public:
    Task(string id = "", int value = 0){
      this->id = id;
      this->value = value;
    }
  int getValue(){return value;}
    bool operator>( const Task & task){
      return (this->value > task.value);
    } 
    bool operator==( const string & id){
      return (this->id == id);
    } 
    bool operator<( const Task & task){
      return (this->value < task.value);
    } 
    friend ostream & operator<<( ostream &, const Task &);
};
 ostream & operator<<( ostream & salida, const Task & task){
   salida << task.id << " :: " << task.value;
   return salida;
 }
