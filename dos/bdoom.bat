if "%DJDIR%" == "" goto error

mkdir CDOOM

set CFLAGS=-Ofast -march=i386 -flto -fwhole-program -fomit-frame-pointer -funroll-loops -fgcse-sm -fgcse-las -fipa-pta -mpreferred-stack-boundary=2 -Wno-attributes
@rem set CFLAGS=%CFLAGS% -Wpedantic -Wall -Wextra

@set GLOBOBJS=
@set GLOBOBJS=%GLOBOBJS% a_taskmn.c
@set GLOBOBJS=%GLOBOBJS% chocdos.c
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
@set GLOBOBJS=%GLOBOBJS% ../src/i_system.c
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

@set GLOBOBJS=%GLOBOBJS% ../src/doom/am_map.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/d_items.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/d_main.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/d_net.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_ammo.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_bexstr.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_cheat.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_doom.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_frame.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_misc.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_ptr.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_sound.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_thing.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/deh_weapon.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/doomstat.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/dstrings.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/f_finale.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/f_wipe.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/g_game.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/hu_lib.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/hu_stuff.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/info.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/m_menu.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/m_random.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_ceilng.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_doors.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_enemy.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_floor.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_inter.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_lights.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_map.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_maputl.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_mobj.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_plats.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_pspr.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_saveg.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_setup.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_sight.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_spec.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_switch.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_telept.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_tick.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/p_user.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/r_bsp.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/r_data.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/r_draw.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/r_main.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/r_plane.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/r_segs.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/r_sky.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/r_things.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/s_sound.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/st_lib.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/st_stuff.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/statdump.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/sounds.c
@set GLOBOBJS=%GLOBOBJS% ../src/doom/wi_stuff.c

gcc %GLOBOBJS% %CFLAGS% -I. -I../opl -I../pcsound -I../src -I../textscreen -DHAVE_DIRENT_H -DPACKAGE_NAME="\"Chocolate Doom for DOS\"" -lemu -o CDOOM/CDOOM.EXE
strip -s CDOOM/CDOOM.EXE
stubedit CDOOM/CDOOM.EXE dpmi=CWSDPR0.EXE


goto end

:error
@echo Set the environment variables before running this script!

:end
