#include <iostream>

#pragma region Override
class Document{
    public:
    virtual void Serialize(float version) = 0;
        //std::cout << "Document::Serialize" << std::endl;
    
};

class Text : public Document{
    public:
    void Serialize(float version) override final{
        std::cout  << "Text::Serialize" << std::endl;
    }
};

class RichText : public Text{
    public:
    //Cannot override because the function is final in base
    /*void Serialize(float version)Override{
        std::cout << "RichText::Serialize" << std::endl
    }*/
};

class XML : public Document{
    public:
    void Serialize(float version)override final{
        std::cout << "XML::Serialize" << std::endl;
    }
};

void Write(Document *p)
{
    p->Serialize(1.1f);
}

#pragma endregion


int main(void)
{
    XML xml;
    Write(&xml);

    return 1;
}

