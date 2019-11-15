class Led
{
private:
    int id_;

public:
    Led(int id);
    void on(int intensity = 100);
    void off();
};