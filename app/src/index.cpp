#include "core/main_controller.h"
#include<locale.h>

using namespace std;

int main () {

   setlocale(LC_ALL, "UTF-8");

   MainController *controller = new MainController();

   controller->index();
   
   return 0;
}