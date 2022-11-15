template <typename T> class City{
  private:
    T name, population;
  public:
    City(T name, T population){
      this->name =name;
      this->population = population;
    }
  int getPopulation(){
    return population;
  }
  string getName(){
    return name;
  }
  void setDatos(T n, T p){
    this->name=n;
    this->population=p;
  }
};
