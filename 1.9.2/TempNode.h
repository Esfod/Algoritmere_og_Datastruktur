#pragma once
#include <string>

namespace ADS101
{
	template <class T>
	class TempNode
	{
	public:
		TempNode(T tegn, TempNode<T>* neste = nullptr);
		std::string toString() const;
		TempNode<T>* hentNeste() const;
		void skrivBaklengs() const;
		static int hentAntall();
		void settNeste(TempNode<T>* neste);
		T hentData() const;
		~TempNode();
	private:
		T m_tegn;
		static int s_antall;
		TempNode<T>* m_neste;
	};

	template <class T>
	int ADS101::TempNode<T>::s_antall = 0;

	template <class T>
	TempNode<T>::TempNode(T tegn, TempNode<T>* neste) : m_tegn(tegn), m_neste(neste)
	{
		//m_tegn = tegn;
		s_antall++;
	}

	template <class T>
	std::string TempNode<T>::toString() const
	{
		std::ostringstream oss;
		oss << m_tegn;
		return oss.str();
	}

	template <class T>
	TempNode<T>* TempNode<T>::hentNeste() const
	{
		return m_neste;
	}

	template <class T>
	void TempNode<T>::skrivBaklengs() const
	{
		if (m_neste)
			m_neste->skrivBaklengs();
		std::cout << m_tegn;
	}

	template <class T>
	int TempNode<T>::hentAntall()
	{
		return s_antall;
	}

	template <class T>
	void TempNode<T>::settNeste(TempNode<T>* neste)
	{
		m_neste = neste;
	}

	template <class T>
	TempNode<T>::~TempNode()
	{
		s_antall--;
	}

	template <class T>
	T TempNode<T>::hentData()const
	{
		return m_tegn;
	}
}