#pragma region Override
class Document{
    public:
    virtual void Serialize(float version) {
        std::cout << "Document::Serialize" << std::endl;
    }
};

class Text : public Document{
    public:
    void Serialize(float version) Override Final{
        std::cout  << "Text::Serialize" << std::endl;
    }
};

class RichText :: public Text{
    public:
    //Cannot override because the function is final in base
    /*void Serialize(float version)Override{
        std::cout << "RichText::Serialize" << std::endl
    }*/
};

class XML : public Document{
    public:
};

#pragma endregion