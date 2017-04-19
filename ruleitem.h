#ifndef RULEITEM_H
#define RULEITEM_H

#include <QString>

class RuleItem
{
public:
    RuleItem(QString n, QString e, QString a) : exp(e), name(n), action(a){}
    QString getExp(void){return exp;}
    QString getName(void){return name;}
    QString getAction(void){return action;}
private:
    QString exp;
    QString name;
    QString action;
};

#endif // RULEITEM_H
