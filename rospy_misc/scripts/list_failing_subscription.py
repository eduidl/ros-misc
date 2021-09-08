from __future__ import print_function
from collections import defaultdict

import rosgraph


def topic_type(t, pub_topics):
    matches = [t_type for t_name, t_type in pub_topics if t_name == t]
    if matches:
        return matches[0]
    return None


def main():
    master = rosgraph.Master('/rosnode')
    state = master.getSystemState()
    pub_topics = master.getPublishedTopics('/')
    subs_map = defaultdict(list)

    for topic, nodes in state[1]:
        for node in nodes:
            subs_map[node].append(topic)

    for node, subs in subs_map.items():
        unknowns = [sub for sub in subs if topic_type(sub, pub_topics) is None]

        if unknowns:
            print()
            print(node)
            for unknown in unknowns:
                print('  *', unknown)


if __name__ == '__main__':
    main()
