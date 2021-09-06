#pragma once
#ifndef CharNode_H
#define CharNode_H

#include <string>
namespace ADS101
{
	class CharNode
	{
	public:
		CharNode(char tegn = '0', CharNode* neste = nullptr);
		std::string toString() const;
		CharNode* hentNeste() const;
		void skrivBaklengs() const;
		static int hentAntall();
		void settNeste(CharNode* neste);
		char hentData() const;
		~CharNode();
	private:
		char m_tegn;
		static int s_antall;
		CharNode* m_neste;
	};
}

#endif