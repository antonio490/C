
class AdaSensor : public Sensor
{
    private:
        int humidity; // percentage
        float pressure;
        float temperature;

    public:

        void setHumidity(int Humidity){
            humidity = Humidity;
        }
        int getHumidity()
        {
            return humidity;
        }

        void setPressure(float Pressure){
            pressure = Pressure;
        }
        float getPressure()
        {
            return pressure;
        }

        float setTemperature(float Temperature){
            temperature = Temperature;
        }
        float getTemperature()
        {
            return temperature;
        }
    
};