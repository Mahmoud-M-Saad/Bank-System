#include "admin.h"
#include "client.h"
#include "authFun.h"
#include "screen.h"
using namespace std;

int main() {
	loadAllJSONs();
	start:
	drawText("  NAME BANK");

	Person* user = login();
    user->performAction();

	system("CLS");
	goto start;
};














//! =========================================    
//if (auto a = dynamic_cast<Admin*>(user)) {
//    char subChoice = Validation::valid_sub_choice();
//    switch (subChoice) {
//    case 'A':
//        staffActionsOn<Admin>(admin, 'A', a->getName());
//        break;
//    case 'E':
//        staffActionsOn<Employee>(emp, 'E', a->getName());
//        break;
//    case 'C':
//        staffActionsOn<Client>(client, 'C', a->getName());
//        break;
//    };
//}
//else if (auto e = dynamic_cast<Employee*>(user)) {
//    staffActionsOn<Client>(client, 'C', e->getName());
//}
//else if (auto c = dynamic_cast<Client*>(user)) {
//    clientActions(*c, c->getName());
//};
//! =========================================