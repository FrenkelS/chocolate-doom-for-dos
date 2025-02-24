if "%DJDIR%" == "" goto error

mkdir CDOOM
mkdir CHERETIC
mkdir CHEXEN
mkdir CSTRIFE

powershell -Command "(gc ..\src\i_system.c) -replace 'void I_Error', 'void I_Error2' | Out-File -encoding ASCII i_system.c"

set CFLAGS=-O1 -march=i386 -flto -fwhole-program -fomit-frame-pointer -fgcse-sm -fgcse-las -fipa-pta -mpreferred-stack-boundary=2 -Wno-attributes
@rem set CFLAGS=%CFLAGS% -Wpedantic -Wall -Wextra

@set GLOBOBJS=
@set GLOBOBJS=%GLOBOBJS% a_taskmn.c
@set GLOBOBJS=%GLOBOBJS% chocdos.c
@set GLOBOBJS=%GLOBOBJS% i_error.c
@set GLOBOBJS=%GLOBOBJS% i_system.c
@set GLOBOBJS=%GLOBOBJS% SDL.c
@set GLOBOBJS=%GLOBOBJS% txt_dos.c
@set GLOBOBJS=%GLOBOBJS% txt_util.c

@set GLOBOBJS=%GLOBOBJS% ../src/d_iwad.c
@set GLOBOBJS=%GLOBOBJS% ../src/d_mode.c
@set GLOBOBJS=%GLOBOBJS% ../src/deh_str.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_main.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_timer.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_argv.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_config.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_controls.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_misc.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_io.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_packet.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_petname.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_query.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_sdl.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_structrw.c
@set GLOBOBJS=%GLOBOBJS% ../src/z_zone.c

@set GLOBOBJS=%GLOBOBJS% ../src/setup/compatibility.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/display.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/execute.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/joystick.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/keyboard.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/mainmenu.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/mode.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/mouse.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/multiplayer.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/sound.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/txt_joyaxis.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/txt_joybinput.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/txt_keyinput.c
@set GLOBOBJS=%GLOBOBJS% ../src/setup/txt_mouseinput.c

@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_button.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_checkbox.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_conditional.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_desktop.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_dropdown.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_fileselect.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_gui.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_inputbox.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_io.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_label.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_radiobutton.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_scrollpane.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_separator.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_spinctrl.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_strut.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_table.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_utf8.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_widget.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_window.c
@set GLOBOBJS=%GLOBOBJS% ../textscreen/txt_window_action.c

gcc %GLOBOBJS% %CFLAGS% -I. -I../src -I../textscreen -DEWOULDBLOCK=EAGAIN -DGAME=\"Doom\" -lemu -o CDOOM/CSETUP_.EXE
strip -s CDOOM/CSETUP_.EXE
stubedit CDOOM/CSETUP_.EXE dpmi=CWSDPR0.EXE

copy CDOOM\CSETUP_.EXE CHERETIC
copy CDOOM\CSETUP_.EXE CHEXEN
copy CDOOM\CSETUP_.EXE CSTRIFE

goto end

:error
@echo Set the environment variables before running this script!

:end
