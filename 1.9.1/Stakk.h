#pragma once
#include "Node.h"

namespace ADS101
{
	class Stakk
	{
	public:
		Stakk();
		~Stakk();
		void push(const char& ch);
		void pop();
		char top();
		int size();
		bool empty();
		void writeOutStack();

	private:
		CharNode* m_top;
		CharNode* m_bottom;
	};
}
