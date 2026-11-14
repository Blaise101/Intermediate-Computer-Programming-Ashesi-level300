#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
int main(array ^>^ args) {
	Application::EnableVisualtyles();
	Application::SetCompatibleTextRenderingDefault(false);
	consoleProject1::MyForm form;
	Application::Run(% form);
}