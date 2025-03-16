//
// Created by saeed on 1/2/25.
//

#ifndef SCRIPTNAMEPRINTER_H
#define SCRIPTNAMEPRINTER_H
#include <string>


class ScriptNamePrinter {
    public:
   static  void PrintScriptName(const std::string& scriptName);
private:
    static  std::string ConvertScriptName(const std::string& input);
};



#endif //SCRIPTNAMEPRINTER_H
