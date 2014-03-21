#ifndef LABEL_H
#define LABEL_H

class Label
{
public:
    Label();
    Label(const char*, int);
    Label(const Label&);
    Label& operator=(const Label&);
    ~Label();

    void setContent(const char*);
    void setBarcode(int);

    char* getContent() const;
    int getBarcode() const;

    void print() const;
    void read();
private:
    char* content;
    int barcode;
    void copy(const Label&);
    void del();
};

#endif