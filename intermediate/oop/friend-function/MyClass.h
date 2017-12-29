class MyClass{
  
  private:
    int privateData;
  
    friend void SomeExternalFunction(MyClass &targetObject);
  
  public:
    MyClass();
    ~MyClass();
    
    void memberFunction();

};