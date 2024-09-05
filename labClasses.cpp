#include "header.h"

CFigure* GetFigure(CManager& manager) {
	int id = 0;
	cout << "Укажите идентификатор объекта==>"; cin >> id;
	return manager.GetFigure(id);
}
void ClassesMenu() {
	CManager manager;
	CFigure* gig = 0;
	CFigure* gig2 = 0;
	UCHAR ch = 0;

	string sclass{}, sfile{};
	//CRectangle * rectangle = 0;
	do {
		CLEAR;

		setColor(0x0C);
		cout << "Меню для реализации классов\n\n";
		setColor(0x0F);
		cout << "1 - Создать объект \n";
		cout << "2 - Изменить свойства объекта\n";
		cout << "3 - Нарисовать все объекты\n";
		cout << "4 - Модель родительского класса\n";
		cout << "5 - Соединить линией\n";
		cout << "S - Сохранить объекты\n";
		cout << "L - Загрузить объекты\n";
		cout << "esc - Назад\n";

		ch = _getch();
		switch (ch) {
		case '1': cout << "\n1 - прямоугольник\n";
			cout << "2 - треугольник\n";
			cout << "3 - эллипс\n";
			ch = _getch();
			switch (ch) {
			case '1': gig = new CRectangle(100, 200, 50, 45, RGB(150, 92, 255), RGB(255, 255, 255));
				manager.AddFigure(gig);
				gig->SetId(manager.Count());
				gig->Draw();
				cout << gig->GetName() << endl;
				//DELAY;
				break;
			case '2': gig = new CTriangle(250, 300, 50, 50, RGB(45, 96, 211), RGB(255, 255, 0));
				manager.AddFigure(gig);
				gig->SetId(manager.Count());
				gig->Draw();
				cout << gig->GetName() << endl;
				//DELAY;
				break;
			case '3': gig = new CEllipse(400, 500, 70, 50, RGB(45, 96, 211), RGB(0, 255, 0));
				manager.AddFigure(gig);
				gig->SetId(manager.Count());
				gig->Draw();
				cout << gig->GetName() << endl;
				//DELAY;
				break;
			}
			ch = 0;
			break;
		case '2': ParamMenu(manager); break;
		case '3': CLEAR;
			cout << "1 - Отобразить все фигуры\n";
			cout << "2 - Отобразить фигуру по идентификатору\n";
			cout << "3 - Отобразить фигуру класса\n";
			cout << "4 - Отобразить соединённые фигуры\n";
			ch = _getch();
			switch (ch) {
			case '1': manager.Draw(); break;
			case '2':gig = GetFigure(manager);
				if (gig == NULL) {
					cout << "Объект по идентификатору не найден\n"; //DELAY;
					break;
				}
				gig->Draw();
				break;
			case '4':manager.DrawGraph();
				PAUSE;
				break;
			case '3':
				string sclass{};
				cout << "Введите наименование класса ==> "; cin >> sclass;
				manager.Draw(sclass);
				break;
			}
			//DELAY;
			PAUSE;
			break;
		case 'S':case's':case 'Ы':case'ы':
			cout << "Введите имя файла: "; getline(cin, sfile);
			if (!sfile.empty()) {
				manager.Save(sfile);
			}
			break;
		case 'L':case'l':case 'Д':case'д':
			cout << "Введите имя файла: "; getline(cin, sfile);
			if (!sfile.empty()) {
				manager.Load(sfile);
			}
			break;
		case '5':
			//CLEAR;
			////cout << "Введите идентификаторы объектов для соединения:\n";
			//CFigure* gig1;
			//CFigure* gig2;
			//cout << "Объект 1\n";
			//do {
			//	gig1 = GetFigure(manager);
			//} while (gig1 == NULL);
			//cout << "Объект 2\n";
			//do {
			//	gig2 = GetFigure(manager);
			//} while (gig2 == NULL);
			//gig1->cX(gig2->X());
			//gig1->cY(gig2->Y());
			//break;
			int i;
			cout << "Введите идентификатор объекта 1: "; cin >> i;
			gig = manager.GetFigure(i);
			cout << "Введите идентификатор объекта 2: "; cin >> i;
			gig2 = manager.GetFigure(i);
			manager.AddUnion(gig, gig2);
			manager.DrawGraph();
			break;
		case '4'://что		
			CFigure * gig = GetFigure(manager);
			if (gig == 0) {
				//ClearScreen();
				for (int i = 1; i < 32; i++) {
					//SetColor(0, i);
					//point(5, 10);
					
				}
				cout << "!!!!!  Указатель = NULL. ОБЪЕКТ НЕ СОЗДАН  !!!!!";
				Sleep(100);
				break;
			}
			cout << "Параметры класса от родителя. \n";
			cout << "X=" << gig->Left() << "  Y =" << gig->Top() << endl;
			cout << "Width=" << gig->Width() << "  Height" << gig->Height() << endl;
			cout << "X2=" << gig->Right() << "  Y2=" << gig->Bottom() << endl;
			cout << "BrushColor=" << gig->BrushColor() << "  PenColor=" << gig->PenColor() << endl;
			//CID* cid = rectangle;
			//gig->SetId(15);
			cout << "Id = " << gig->GetId() << endl;
			cout << "Name = " << gig->GetName() << endl;
			cout << "Фигура" << endl;
			gig->Draw();
			//DELAY;
			PAUSE;
			break;
		}
	} while (ch != 27);
}

void ParamMenu(CManager& pmanager) {
	UCHAR ch = 0;
	int val = 0;
	CFigure* gig = 0;
	do {
		CLEAR;

		cout << " Меню для изсенения классов классов\n\n";
		cout << "1 - Местоположение объекта\n";
		cout << "2 - Размеры объекта\n";
		cout << "3 - Цвета заливки объекта\n";
		cout << "esc - Назад\n";

		ch = _getch();
		switch (ch) {
		case '1':
			gig = GetFigure(pmanager);
			if (gig == NULL) {
				cout << "ID НЕ НАЙДЕН!!!";
				break;
			}
			cout << "Введите 0, если параметр не меняется!!!\n\n";
			cout << "Введите координату X (" << gig->X() << ") "; cin >> val;
			if (val > 0) gig->X(val);
			cout << "Введите координату Y (" << gig->Y() << ") "; cin >> val;
			if (val > 0) gig->Y(val);
			break;
		case '2':
			gig = GetFigure(pmanager);
			if (gig == NULL) {
				cout << "ID НЕ НАЙДЕН!!!";
				break;
			}
			cout << "Введите 0, если параметр не меняется!!!\n\n";
			cout << "Введите ширину(" << gig->Width() << ") "; cin >> val;
			if (val > 0) gig->Width(val);
			cout << "Введите высоту(" << gig->Height() << ") "; cin >> val;
			if (val > 0) gig->Height(val);
			break;
		case '3':
			gig = GetFigure(pmanager);
			if (gig == NULL) {
				cout << "ID НЕ НАЙДЕН!!!";
				break;
			}
			cout << "Введите -1, если параметр не меняется!!!\n\n";
			cout << "Введите цвет фона(" << gig->BrushColor() << ") "; cin >> val;
			if (val > 0) gig->BrushColor(val);
			cout << "Введите цвет контура(" << gig->Height() << ") "; cin >> val;
			if (val > 0)gig->PenColor(val); break;
			if (gig != 0) gig->Draw();
			break;
		}
	} while (ch != 27);
}