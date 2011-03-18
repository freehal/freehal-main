/*
 * This file is part of FreeHAL 2010.
 *
 * Copyright(c) 2006, 2007, 2008, 2009, 2010 Tobias Schulz and contributors.
 * http://freehal.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "hal2009-ipc.h"

void (*hal2009_send_signal_func)(string vfile, string data) = 0;
std::vector<std::pair<string, string> > signals_to_child;

extern "C" void hal2009_send_signal(const char* vfile, const char* data) {
    cout << "signals_to_child.push_back(make_pair<string, string>(\"" << vfile << "\", \"" << data << "\"));\"" << endl;
    signals_to_child.push_back(make_pair<string, string>(vfile, data));

    hal2009_send_signals();
}
extern "C" void hal2009_send_signals() {
    if (hal2009_send_signal_func) {
        for (int i = 0; i < signals_to_child.size(); ++i) {
            cout << "hal2009_send_signal_func(\"" << signals_to_child[i].first << "\", \"" << signals_to_child[i].second << "\");" << endl;
            hal2009_send_signal_func(signals_to_child[i].first, signals_to_child[i].second);
        }
        signals_to_child.clear();
    }
}

