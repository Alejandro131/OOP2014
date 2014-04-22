#ifndef MONEY_STREAM_HPP
#define MONEY_STREAM_HPP

class MoneyStream
{
public:
    MoneyStream(unsigned int);
    MoneyStream(const MoneyStream&);
    ~MoneyStream();

    MoneyStream& operator=(const MoneyStream&);

    unsigned int getSize() const;
    double getValue(unsigned int);

    bool isAvailable(unsigned int) const;
    bool hasAvailable() const;

private:
    double* stream;
    unsigned int size;

    static bool seeded;

    void copy(const MoneyStream&);
    void del();
};

#endif
