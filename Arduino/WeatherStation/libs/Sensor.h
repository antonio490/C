
#include <string>

class Sensor
{
    private:
        int id;
        string name;
        float value;

    Sensor();

    public:

        Sensor(int id, string name) 
        {
            this->id = id;
            this->name = name;
            init();
        }

        void init() 
        {
            pinMode(pin, OUTPUT);
        }

        void setName(string name) {
            this->name = name;
        }
        string getName() {
            return name;
        }

        void setId(int id) {
            this->id = id;
        }
        int getId() {
            return id;
        }

        void setValue(float value) {
            this->value = value;
        }
        float getValue() {
            return value;
        }
};