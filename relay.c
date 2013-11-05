/*
 *  This file is part of carbon-c-relay.
 *
 *  carbon-c-relay is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  carbon-c-relay is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with carbon-c-relay.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>

#include "carbon-hash.h"


int main() {
	carbon_ring *ring;
	carbon_ring *targ[2];
	char *s[] = { "In", "boomwortels", "Gelderse", "heeft" };
	int i;

	ring = carbon_addnode(NULL, "ip1", 2003);
	ring = carbon_addnode(ring, "ip2", 2003);
	//ring = carbon_addnode(ring, "ip3", 2003);

	/*
	for (; ring != NULL; ring = ring->next)
		printf("(%d, %s:%d)\n", ring->pos, ring->server, ring->port);
	*/

	for (i = 0; i < 4; i++) {
		carbon_get_nodes(targ, ring, 2, s[i]);
		printf("%s: %s (%d)\n", s[i], targ[0]->server, targ[0]->pos);
		printf("%s: %s (%d)\n", s[i], targ[1]->server, targ[1]->pos);
	}

	return 0;
}
