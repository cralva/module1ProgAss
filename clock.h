class clockType {
public:
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType&) const; //const is everywhere in this function. we can put const in different places and it plays a different role depending on where it is

private:
    int hr;
    int min;
    int sec;
};