#include <lua.hpp>
#include <graphics.h>
#include <Windows.h>

HWND hwnd;      // ���ھ��

MOUSEMSG msg;   // �����Ϣ

// ��ʼ�����ڣ�2���������ڿ�ȡ����ڸ߶�
extern "C" int init(lua_State * L)
{
    int width = lua_tonumber(L, 1);
    int height = lua_tonumber(L, 2);
    hwnd = initgraph(width, height, EW_DBLCLKS);
    return 0;
}

// ʹ�õ�ǰ����ɫ�����Ļ���޲���
extern "C" int clear(lua_State * L)
{
    cleardevice();
    return 0;
}

// �رյ�ǰ���ڣ��޲���
extern "C" int close(lua_State * L)
{
    closegraph();
    return 0;
}

// ���ô��ڱ��⣬1�����������ַ���
extern "C" int setTitle(lua_State * L)
{
    const char* title = lua_tostring(L, 1);
    SetWindowTextA(hwnd, title);
    return 0;
}

// ���ñ�����ɫ��3������R��G��B
extern "C" int setBGColor(lua_State * L)
{
    int R = lua_tonumber(L, 1);
    int G = lua_tonumber(L, 2);
    int B = lua_tonumber(L, 3);
    setbkcolor(RGB(R, G, B));
    return 0;
}

// ���ñ�����ɫ���ģʽ��1������ģʽ��
// ��ѡֵΪ��OPAQUE�������õ�ǰ����ɫ��䣩��TRANSPARENT��͸��������
extern "C" int setBGMode(lua_State * L)
{
    const char* mode = lua_tostring(L, 1);
    if (!strcmp(mode, "TRANSPARENT"))
    {
        setbkmode(TRANSPARENT);
    }
    else if (!strcmp(mode, "OPAQUE"))
    {
        setbkmode(OPAQUE);
    }
    return 0;
}

// ���������ɫ��3������R��G��B
extern "C" int setFillColor(lua_State * L)
{
    int R = lua_tonumber(L, 1);
    int G = lua_tonumber(L, 2);
    int B = lua_tonumber(L, 3);
    setfillcolor(RGB(R, G, B));
    return 0;
}

// ���û�����ɫ��3������R��G��B
extern "C" int setLineColor(lua_State * L)
{
    int R = lua_tonumber(L, 1);
    int G = lua_tonumber(L, 2);
    int B = lua_tonumber(L, 3);
    setlinecolor(RGB(R, G, B));
    return 0;
}

// ����������ɫ��3������R��G��B
extern "C" int setTextColor(lua_State * L)
{
    int R = lua_tonumber(L, 1);
    int G = lua_tonumber(L, 2);
    int B = lua_tonumber(L, 3);
    settextcolor(RGB(R, G, B));
    return 0;
}

// ���������ɫ��1������������
// ��ѡֵΪ��"SOLID"��ʵ�ߣ���"DASH"��----����"DOT"��������������"DASHDOT"��-��-��-��-����"DASHDOTDOT"��-����-����-��������"NULL"�����ɼ���
extern "C" int setLineStyle(lua_State * L)
{
    const char* style = lua_tostring(L, 1);
    if (!strcmp(style, "SOLID"))
    {
        setlinestyle(PS_SOLID);
    }
    else if (!strcmp(style, "DASH"))
    {
        setlinestyle(PS_DASH);
    }
    else if (!strcmp(style, "DOT"))
    {
        setlinestyle(PS_DOT);
    }
    else if (!strcmp(style, "DASHDOT"))
    {
        setlinestyle(PS_DASHDOT);
    }
    else if (!strcmp(style, "DASHDOTDOT"))
    {
        setlinestyle(PS_DASHDOTDOT);
    }
    else if (!strcmp(style, "NULL"))
    {
        setlinestyle(PS_NULL);
    }
    return 0;
}

// �������ص㣬5������x���ꡢy���ꡢR��G��B
extern "C" int drawPixel(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int R = lua_tonumber(L, 3);
    int G = lua_tonumber(L, 4);
    int B = lua_tonumber(L, 5);
    putpixel(x, y, RGB(R, G, B));
    return 0;
}

// ����ֱ�ߣ�4��������ʼλ��x���ꡢ��ʼλ��y���ꡢ��ֹλ��x���ꡢ��ֹλ��y����
extern "C" int drawLine(lua_State * L)
{
    int x1 = lua_tonumber(L, 1);
    int y1 = lua_tonumber(L, 2);
    int x2 = lua_tonumber(L, 3);
    int y2 = lua_tonumber(L, 4);
    line(x1, y1, x2, y2);
    return 0;
}

// ���������Բ�Ǿ��Σ�6������������������ꡢ�����ϱ������ꡢ�����ұ������ꡢ�����±������ꡢԲ����Բ��ȡ�Բ����Բ�߶�
extern "C" int drawRoundrect(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    int ellipsewidth = lua_tonumber(L, 5);
    int ellipseheight = lua_tonumber(L, 6);
    roundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
    return 0;
}

// ���������Բ�Ǿ��Σ�6������������������ꡢ�����ϱ������ꡢ�����ұ������ꡢ�����±������ꡢԲ����Բ��ȡ�Բ����Բ�߶�
extern "C" int drawFillRoundrect(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    int ellipsewidth = lua_tonumber(L, 5);
    int ellipseheight = lua_tonumber(L, 6);
    fillroundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
    return 0;
}

// ��������ޱ߿�Բ�Ǿ��Σ�6������������������ꡢ�����ϱ������ꡢ�����ұ������ꡢ�����±������ꡢԲ����Բ��ȡ�Բ����Բ�߶�
extern "C" int drawSolidRoundrect(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    int ellipsewidth = lua_tonumber(L, 5);
    int ellipseheight = lua_tonumber(L, 6);
    solidroundrect(left, top, right, bottom, ellipsewidth, ellipseheight);
    return 0;
}

// �����������Բ��4��������Բ���о������Ͻ�x���ꡢ��Բ���о������Ͻ�y���ꡢ��Բ���о������½�x���ꡢ��Բ���о������½�y����
extern "C" int drawEllipse(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    ellipse(left, top, right, bottom);
    return 0;
}

// �����������Բ��4��������Բ���о������Ͻ�x���ꡢ��Բ���о������Ͻ�y���ꡢ��Բ���о������½�x���ꡢ��Բ���о������½�y����
extern "C" int drawFillEllipse(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    fillellipse(left, top, right, bottom);
    return 0;
}

// ��������ޱ߿���Բ��4��������Բ���о������Ͻ�x���ꡢ��Բ���о������Ͻ�y���ꡢ��Բ���о������½�x���ꡢ��Բ���о������½�y����
extern "C" int drawSolidEllipse(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    solidellipse(left, top, right, bottom);
    return 0;
}

// ���������Բ��3������Բ��x���ꡢԲ��y���ꡢ�뾶
extern "C" int drawCircle(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int radius = lua_tonumber(L, 3);
    circle(x, y, radius);
    return 0;
}

// ���������Բ��3������Բ��x���ꡢԲ��y���ꡢ�뾶
extern "C" int drawFillCircle(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int radius = lua_tonumber(L, 3);
    fillcircle(x, y, radius);
    return 0;
}

// ��������ޱ߿�Բ��3������Բ��x���ꡢԲ��y���ꡢ�뾶
extern "C" int drawSolidCircle(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int radius = lua_tonumber(L, 3);
    solidcircle(x, y, radius);
    return 0;
}

// �����������Σ�4������������������ꡢ�����ϱ������ꡢ�����ұ������ꡢ�����±�������
extern "C" int drawRectangle(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    rectangle(left, top, right, bottom);
    return 0;
}

// �����������Σ�4������������������ꡢ�����ϱ������ꡢ�����ұ������ꡢ�����±�������
extern "C" int drawFillRectangle(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    fillrectangle(left, top, right, bottom);
    return 0;
}

// ����������ޱ߿���Σ�4������������������ꡢ�����ϱ������ꡢ�����ұ������ꡢ�����±�������
extern "C" int drawSolidRectangle(lua_State * L)
{
    int left = lua_tonumber(L, 1);
    int top = lua_tonumber(L, 2);
    int right = lua_tonumber(L, 3);
    int bottom = lua_tonumber(L, 4);
    solidrectangle(left, top, right, bottom);
    return 0;
}

// ���õ�ǰ������ʽ��3����������߶ȡ������ȣ�0Ϊ����Ӧ������������
extern "C" int setTextStyle(lua_State * L)
{
    int height = lua_tonumber(L, 1);
    int width = lua_tonumber(L, 2);
    const char* name = lua_tostring(L, 3);
    int num = MultiByteToWideChar(0, 0, name, -1, NULL, 0);
    wchar_t* w_name = new wchar_t[num];
    MultiByteToWideChar(0, 0, name, -1, w_name, num);
    settextstyle(height, width, w_name);
    return 0;
}

// ��ָ��λ������ַ�����3������x���ꡢy���ꡢ�ַ�������
extern "C" int drawText(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    const char* content = lua_tostring(L, 3);
    int num = MultiByteToWideChar(0, 0, content, -1, NULL, 0);
    wchar_t* w_content = new wchar_t[num];
    MultiByteToWideChar(0, 0, content, -1, w_content, num);
    outtextxy(x, y, w_content);
    return 0;
}

// ��ָ��λ�û���ͼƬ��5������x���ꡢy���ꡢͼƬ��ȡ�ͼƬ�߶ȡ�ͼƬ·��
extern "C" int drawImage(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int width = lua_tonumber(L, 3);
    int height = lua_tonumber(L, 4);
    const char* path = lua_tostring(L, 5);
    int num = MultiByteToWideChar(0, 0, path, -1, NULL, 0);
    wchar_t* w_path = new wchar_t[num];
    MultiByteToWideChar(0, 0, path, -1, w_path, num);
    IMAGE image;
    loadimage(&image, w_path, width, height);
    putimage(x, y, &image);
    return 0;
}

// ��ָ��λ�û���͸��ͼƬ��5������x���ꡢy���ꡢͼƬ��ȡ�ͼƬ�߶ȡ�ͼƬ·��
extern "C" int drawTransImage(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int width = lua_tonumber(L, 3);
    int height = lua_tonumber(L, 4);
    const char* path = lua_tostring(L, 5);
    int num = MultiByteToWideChar(0, 0, path, -1, NULL, 0);
    wchar_t* w_path = new wchar_t[num];
    MultiByteToWideChar(0, 0, path, -1, w_path, num);
    IMAGE srcimg;
    loadimage(&srcimg, w_path, width, height);

    DWORD* dst = GetImageBuffer(NULL);
    DWORD* src = GetImageBuffer(&srcimg);
    int src_width = (&srcimg)->getwidth();
    int src_height = (&srcimg)->getheight();
    int dst_width = getwidth();
    int dst_height = getheight();

    int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;
    int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;
    if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }
    if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }
    
    dst += dst_width * y + x;

    for (int iy = 0; iy < iheight; iy++)
    {
        for (int ix = 0; ix < iwidth; ix++)
        {
            int sa = ((src[ix] & 0xff000000) >> 24);
            int sr = ((src[ix] & 0xff0000) >> 16);
            int sg = ((src[ix] & 0xff00) >> 8);	
            int sb = src[ix] & 0xff;			
            int dr = ((dst[ix] & 0xff0000) >> 16);
            int dg = ((dst[ix] & 0xff00) >> 8);
            int db = dst[ix] & 0xff;

            dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
                | ((sg + dg * (255 - sa) / 255) << 8)
                | (sb + db * (255 - sa) / 255);
        }
        dst += dst_width;
        src += src_width;
    }

    return 0;
}

// ���ָ������6���������x���ꡢ���y���ꡢR��G��B���������
// ������Ϳ�ѡֵΪ��"BORDER"����䶯��������ָ����ɫΧ�ɵķ�����򣩣�"SURFACE"����䶯��������ָ����ɫ���������棩
extern "C" int floodFill(lua_State * L)
{
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L, 2);
    int R = lua_tonumber(L, 3);
    int G = lua_tonumber(L, 4);
    int B = lua_tonumber(L, 5);
    const char* fillType = lua_tostring(L, 6);
    if (!strcmp(fillType, "SURFACE"))
    {
        floodfill(x, y, RGB(R, G, B), FLOODFILLSURFACE);
    }
    else
    {
        floodfill(x, y, RGB(R, G, B), FLOODFILLBORDER);
    }
    return 0;
}

// �����¼����޲���
extern "C" int captureEvent(lua_State * L)
{
    msg = GetMouseMsg();
    return 0;
}

// �жϽ����¼����ͣ�1������������
// ��ѡֵΪ��"MOUSEMOVE"������ƶ�����"MOUSEWHELL"���������ƶ�����"LBUTTONDOWN"�����������£���"LBUTTONUP"��������̧�𣩣�"LBUTTONDBLCLK"��������˫������"MBUTTONDOWN"������м����£���"MBUTTONUP"������м�̧�𣩣�"MBUTTONDBLCLK"������м�˫������"RBUTTONDOWN"������Ҽ����£���"RBUTTONUP"������Ҽ�̧�𣩣�"RBUTTONDBLCLK"������Ҽ�˫������"CTRLDOWN"��Ctrl�����£���"SHIFTDOWN"��Shift�����£�
// 1������ֵ��0 - ���ǵ�ǰ�¼���1 - �ǵ�ǰ�¼���-1 - �����ڵ�ǰ�¼�
extern "C" int checkEventType(lua_State * L)
{
    const char* eventType = lua_tostring(L, 1);
    int result = -1;
    if (!strcmp(eventType, "MOUSEMOVE"))
    {
        if (msg.uMsg == WM_MOUSEMOVE)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "MOUSEWHELL"))
    {
        if (msg.uMsg == WM_MOUSEWHEEL)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "LBUTTONDOWN"))
    {
        if (msg.uMsg == WM_LBUTTONDOWN)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "LBUTTONDBLCLK"))
    {
        if (msg.uMsg == WM_LBUTTONDBLCLK)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "MBUTTONDOWN"))
    {
        if (msg.uMsg == WM_MBUTTONDOWN)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "MBUTTONUP"))
    {
        if (msg.uMsg == WM_MBUTTONUP)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "MBUTTONDBLCLK"))
    {
        if (msg.uMsg == WM_MBUTTONDBLCLK)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "RBUTTONDOWN"))
    {
        if (msg.uMsg == WM_RBUTTONDOWN)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "RBUTTONUP"))
    {
        if (msg.uMsg == WM_RBUTTONUP)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "RBUTTONDBLCLK"))
    {
        if (msg.uMsg == WM_RBUTTONDBLCLK)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "CTRLDOWN"))
    {
        if (msg.mkCtrl)
            result = 1;
        else
            result = 0;
    }
    else if (!strcmp(eventType, "SHIFTDOWN"))
    {
        if (msg.mkShift)
            result = 1;
        else
            result = 0;
    }
    lua_pushnumber(L, result);
    return 1;
}

// ��ȡ��ǰ���λ�ã��޲���
// 2������ֵ��x���ꡢy����
extern "C" int getMousePosition(lua_State * L)
{
    MOUSEMSG msg = GetMouseMsg();
    lua_pushnumber(L, msg.x);
    lua_pushnumber(L, msg.y);
    return 2;
}

// ��ʼ������ͼ���޲���
extern "C" int beginBatchDraw(lua_State * L)
{
    BeginBatchDraw();
    return 0;
}

// ִ��δ��ɻ�ͼ�����޲���
extern "C" int flushBatchDraw(lua_State * L)
{
    FlushBatchDraw();
    return 0;
}

// ����������ͼ���޲���
extern "C" int endBatchDraw(lua_State * L)
{
    EndBatchDraw();
    return 0;
}

// ��ͣ�����޲���
extern "C" int pause(lua_State * L)
{
    system("pause");
    return 0;
}

// �������ָ��ʱ�䣬1����������ʱ�䣨��λ�����룩
extern "C" int sleep(lua_State * L)
{
    int delay = lua_tonumber(L, 1);
    Sleep(delay);
    return 0;
}



static luaL_Reg cMethods[] = {
    { "Init", init },
    { "Clear", clear },
    { "Close", close },
    { "SetTitle", setTitle },
    { "SetBGColor", setBGColor },
    { "SetBGMode", setBGMode },
    { "SetFillColor", setFillColor },
    { "SetLineColor", setLineColor },
    { "SetTextColor", setTextColor },
    { "SetLineStyle", setLineStyle },
    { "Point", drawPixel},
    { "Line", drawLine },
    { "Roundrect" , drawRoundrect },
    { "FillRoundrect" , drawFillRoundrect },
    { "SolidRoundrect", drawSolidRoundrect },
    { "Ellipse", drawEllipse },
    { "FillEllipse", drawFillEllipse },
    { "SolidEllipse", drawSolidEllipse},
    { "Circle", drawCircle },
    { "FillCircle", drawFillCircle },
    { "SolidCircle", drawSolidCircle },
    { "Rectangle", drawRectangle },
    { "FillRectangle", drawFillRectangle },
    { "SolidRectangle", drawSolidRectangle },
    { "SetTextStyle", setTextStyle },
    { "DrawText", drawText },
    { "DrawImage", drawImage },
    { "DrawTransImage", drawTransImage },
    { "FloodFill", floodFill },
    { "CaptureEvent", captureEvent},
    { "CheckEventType", checkEventType},
    { "GetMousePosition", getMousePosition},
    { "BeginBatchDraw", beginBatchDraw },
    { "FlushBatchDraw", flushBatchDraw },
    { "EndBatchDraw", endBatchDraw },
    { "Pause", pause },
    { "Sleep", sleep },
    { NULL, NULL }
};

extern "C" __declspec(dllexport)
int luaopen_EasyDraw(lua_State * L)
{
    luaL_newlib(L, cMethods);
    return 1;
}