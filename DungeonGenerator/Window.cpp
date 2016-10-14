#include "Window.h"

//
// Init
//
bool Window::Init(HINSTANCE hInst, const char* title, int width, int height, int posX, int posY)
{
	m_hInst = hInst;
	m_Title = title;
	m_Width = width;
	m_Height = height;
	m_PosX = posX;
	m_PosY = posY;

	ZeroMemory(&m_WndEx, sizeof(WNDCLASSEX));
	m_WndEx.cbSize = sizeof(WNDCLASSEX);
	m_WndEx.style = CS_CLASSDC;
	m_WndEx.lpfnWndProc = MsgProc;
	m_WndEx.hInstance = m_hInst;
	m_WndEx.lpszClassName = (LPCWSTR)"Window-Class";

	// Register the Window
	RegisterClassEx(&m_WndEx);

	// Fenster erstellen
	m_Window = CreateWindow(m_WndEx.lpszClassName, 
							(LPCWSTR)m_Title,
							WS_OVERLAPPEDWINDOW|WS_VISIBLE,
							m_PosX, m_PosY,
							m_Width, m_Height,
							GetDesktopWindow(),
							NULL, m_WndEx.hInstance,
							NULL);

	if(m_Window == NULL)
	{
		return false;
	}

	return true;
}

void Window::Destroy()
{
	UnregisterClass((LPWSTR)"Window-Class", m_hInst);
}

LRESULT CALLBACK MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	case WM_PAINT:
		{
			ValidateRect(hWnd, NULL);
			return 0;
		}
	case WM_KEYDOWN:
		{
			switch(wParam)
			{
			case VK_ESCAPE:
				{
					PostQuitMessage(0);
					return 0;
				}
			}
		}
		break;
	}

	return (DefWindowProc(hWnd, message, wParam, lParam));
}