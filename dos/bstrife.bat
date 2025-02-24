if "%DJDIR%" == "" goto error

mkdir CSTRIFE

powershell -Command "(gc ..\src\i_system.c) -replace 'void I_Error', 'void I_Error2' | Out-File -encoding ASCII i_system.c"

set CFLAGS=-Ofast -march=i386 -flto -fwhole-program -fomit-frame-pointer -funroll-loops -fgcse-sm -fgcse-las -fipa-pta -mpreferred-stack-boundary=2 -Wno-attributes
@rem set CFLAGS=%CFLAGS% -Wpedantic -Wall -Wextra

@set GLOBOBJS=
@set GLOBOBJS=%GLOBOBJS% a_taskmn.c
@set GLOBOBJS=%GLOBOBJS% chocdos.c
@set GLOBOBJS=%GLOBOBJS% i_error.c
@set GLOBOBJS=%GLOBOBJS% i_system.c
@set GLOBOBJS=%GLOBOBJS% opl.c
@set GLOBOBJS=%GLOBOBJS% pcsound.c
@set GLOBOBJS=%GLOBOBJS% SDL.c
@set GLOBOBJS=%GLOBOBJS% textscreen.c

@set GLOBOBJS=%GLOBOBJS% ../src/d_event.c
@set GLOBOBJS=%GLOBOBJS% ../src/d_iwad.c
@set GLOBOBJS=%GLOBOBJS% ../src/d_loop.c
@set GLOBOBJS=%GLOBOBJS% ../src/d_mode.c
@set GLOBOBJS=%GLOBOBJS% ../src/deh_io.c
@set GLOBOBJS=%GLOBOBJS% ../src/deh_main.c
@set GLOBOBJS=%GLOBOBJS% ../src/deh_mapping.c
@set GLOBOBJS=%GLOBOBJS% ../src/deh_str.c
@set GLOBOBJS=%GLOBOBJS% ../src/deh_text.c
@set GLOBOBJS=%GLOBOBJS% ../src/gusconf.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_endoom.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_glob.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_input.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_joystick.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_main.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_musicpack.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_oplmusic.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_pcsound.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_sound.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_sdlmusic.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_sdlsound.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_timer.c
@set GLOBOBJS=%GLOBOBJS% ../src/i_video.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_argv.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_bbox.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_cheat.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_config.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_controls.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_fixed.c
@set GLOBOBJS=%GLOBOBJS% ../src/m_misc.c
@set GLOBOBJS=%GLOBOBJS% ../src/memio.c
@set GLOBOBJS=%GLOBOBJS% ../src/midifile.c
@set GLOBOBJS=%GLOBOBJS% ../src/mus2mid.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_client.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_common.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_dedicated.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_gui.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_io.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_loop.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_packet.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_petname.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_query.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_sdl.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_server.c
@set GLOBOBJS=%GLOBOBJS% ../src/net_structrw.c
@set GLOBOBJS=%GLOBOBJS% ../src/sha1.c
@set GLOBOBJS=%GLOBOBJS% ../src/tables.c
@set GLOBOBJS=%GLOBOBJS% ../src/v_diskicon.c
@set GLOBOBJS=%GLOBOBJS% ../src/v_video.c
@set GLOBOBJS=%GLOBOBJS% ../src/w_checksum.c
@set GLOBOBJS=%GLOBOBJS% ../src/w_file.c
@set GLOBOBJS=%GLOBOBJS% ../src/w_file_stdc.c
@set GLOBOBJS=%GLOBOBJS% ../src/w_main.c
@set GLOBOBJS=%GLOBOBJS% ../src/w_merge.c
@set GLOBOBJS=%GLOBOBJS% ../src/w_wad.c
@set GLOBOBJS=%GLOBOBJS% ../src/z_zone.c

@set GLOBOBJS=%GLOBOBJS% ../src/strife/am_map.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/d_items.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/d_main.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/d_net.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/deh_ammo.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/deh_cheat.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/deh_frame.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/deh_misc.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/deh_ptr.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/deh_sound.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/deh_strife.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/deh_thing.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/deh_weapon.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/doomstat.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/dstrings.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/f_finale.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/f_wipe.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/g_game.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/hu_lib.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/hu_stuff.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/info.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/m_menu.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/m_random.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/m_saves.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_ceilng.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_dialog.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_doors.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_enemy.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_floor.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_inter.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_lights.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_map.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_maputl.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_mobj.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_plats.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_pspr.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_saveg.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_setup.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_sight.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_spec.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_switch.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_telept.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_tick.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/p_user.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/r_bsp.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/r_data.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/r_draw.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/r_main.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/r_plane.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/r_segs.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/r_sky.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/r_things.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/s_sound.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/st_lib.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/st_stuff.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/sounds.c
@set GLOBOBJS=%GLOBOBJS% ../src/strife/wi_stuff.c

gcc %GLOBOBJS% %CFLAGS% -I. -I../opl -I../pcsound -I../src -I../textscreen -DHAVE_DIRENT_H -DGAME=\"Strife\" -lemu -o CSTRIFE/CSTRIFE.EXE
strip -s CSTRIFE/CSTRIFE.EXE
stubedit CSTRIFE/CSTRIFE.EXE dpmi=CWSDPR0.EXE


goto end

:error
@echo Set the environment variables before running this script!

:end
