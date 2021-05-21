#pragma once

enum Sp { Normal, VIP };

enum EventT { B, X, P };

struct Event {
	int ID;
	int TS;
	int TA;
	int LA;
	Sp typ;
	int Pass;
};

