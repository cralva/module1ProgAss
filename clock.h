class clockType {
public:
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTimes(const clockType&) const; 

private:
    int hr;
    int min;
    int sec;
};