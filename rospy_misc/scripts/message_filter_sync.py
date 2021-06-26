import sys

import rospy
import rostopic
from message_filters import Subscriber, TimeSynchronizer


class Sync(object):
    def __init__(self, names):
        self.subscribers = []
        for name in names:
            msg_type = rostopic.get_topic_class(name)
            self.subscribers.append(Subscriber(name, msg_type[0]), queues_size=1)
        self.ts = TimeSynchronizer(self.subscribers, queue_size=1)
        self.ts.registerCallback(self.callback)

    def callback(self, *msgs):
        rospy.loginfo('{}'.format(msgs[0].header.stamp))


def main():
    rospy.init_node('message_filters_sync')
    args = sys.argv[1:]

    if not args:
        rospy.logerr('Invalid argments')
        return

    node = Sync(args)  # noqa: F841
    rospy.spin()


if __name__ == '__main__':
    main()
