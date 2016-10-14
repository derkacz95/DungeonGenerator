#pragma once

#include <Windows.h>


//
// Message Callback Function
//
LRESULT CALLBACK MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//
// Window Class
//
// Show a basic Window
//
class Window
{
public: 

	//
	// Memberfunctions
	//
	bool Init();
	bool Init(const char* title);
	bool Init(const char* title, int width, int height);
	bool Init(const char* title, int width, int height, int posX, int posY);
	bool Init(int width, int height);
	bool Init(int width, int height, int posX, int posY);
	bool Init(HINSTANCE hInst, int width, int height);
	bool Init(HINSTANCE hInst, int width, int height, int posX, int posY);
	bool Init(HINSTANCE hInst, const char* title, int width, int height);
	bool Init(HINSTANCE hInst, const char* title, int width, int height, int posX, int posY);

	void Destroy();

	//
	// Get Functions
	//
	inline HWND GetHandle() {return m_Window;}
	inline int	GetHeight()	{return m_Height; }
	inline int	GetWidth()	{return m_Width;}
	inline int	GetPosX()	{return m_PosX; }
	inline int	GetPosY()	{return m_PosY; }
	inline const char* GetTitle() {return m_Title; }

	//
	// Set Functions
	//
	inline void SetHandle(HWND handle)	{m_Window = handle;}
	inline void SetHeight(int height)	{m_Height = height;}
	inline void SetWidth(int width)		{m_Width = width; }
	inline void SetPosX(int posX)		{m_PosX = posX; }
	inline void SetPosY(int posY)		{m_PosY = posY; }
	inline const char* SetTitle(const char* title) {m_Title = title;}

	inline operator HWND() const {return m_Window; } // Convert into HWND

private:

	//
	// Variables
	//
	HWND m_Window;
	HINSTANCE m_hInst;
	const char* m_Title;
	int m_Width;
	int m_Height;
	int m_PosX;
	int m_PosY;

	WNDCLASSEX m_WndEx;
};