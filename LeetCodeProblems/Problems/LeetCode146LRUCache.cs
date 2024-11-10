namespace LeetCodeProblems.Problems;

public class LeetCode146LRUCache : BaseProblemClass
{
    public class LRUCache
    {
        private int _capacity;
        private Node _head;
        private Node _tail;
        private Dictionary<int, Node> _nodes = [];

        public LRUCache(int capacity)
        {
            _capacity = capacity;
        }

        public int Get(int key)
        {
            if (!_nodes.TryGetValue(key, out var node))
                return -1;
            if (node == _head)
                return node.value;
            var previous=node.previous;
            var next=node.next;
            if (previous != null && next != null)
            {
                previous.next = next;
                next.previous = previous;
                node.previous = null;
                node.next = _head;
                _head.previous = node;
                _head = node;
            }
            else if (next == null)
            {
                _tail = node.previous;
                _tail.next = null;
                node.previous = null;
                node.next = _head;
                _head.previous = node;
                _head = node;
            }
            return node.value;
        }

        public void Put(int key, int value)
        {
            if (_capacity == 0)
                return;
            if (_capacity == 1)
            {
                _nodes = [];
                _head = new(value);
                _nodes[key] = _head;
                return;
            }

            if (_nodes.Count < _capacity)

            {
                if (_head == null)
                {
                    _head = new(value);
                    _nodes.Add(key, _head);
                    return;
                }

                if (_tail == null)
                {
                    if (_nodes.ContainsKey(key))
                    {
                        _head.value = value;
                        return;
                    }

                    _tail = new(value);
                    _head.previous = _tail;
                    _tail.next = _head;
                    (_head, _tail) = (_tail, _head);
                    _nodes.Add(key, _head);
                    return;
                }

                if (!_nodes.ContainsKey(key))
                {
                    var node = new Node(value);
                    node.next = _head;
                    _head.previous = node;
                    _head.next = node;
                    _head = node;
                    _nodes.Add(key, _head);
                    return;
                }
            }

            if (!_nodes.ContainsKey(key))
            {
                var oldKey = _nodes.First(n => n.Value == _tail).Key;
                _nodes.Remove(oldKey);
                _tail.value = value;
                var prev = _tail.previous;
                prev.next = null;
                _tail.previous = null;
                _tail.next = _head;
                _head.previous = _tail;
                _head = _tail;
                _tail = prev;
                _nodes.Add(key, _head);
            }
            else
            {
                var node = _nodes[key];
                node.value = value;
                var previous = node.previous;
                var next = node.next;
                if (previous != null && next != null)
                {
                    previous.next = next;
                    next.previous = previous;
                    node.previous = null;
                    node.next = _head;
                    _head.previous = node;
                    _head = node;
                }
                else if (next == null)
                {
                    _tail = node.previous;
                    _tail.next = null;
                    node.previous = null;
                    node.next = _head;
                    _head.previous = node;
                    _head = node;
                }
            }
        }

        public class Node
        {
            public Node(int value)
            {
                this.value = value;
            }

            public int value;
            public Node next;
            public Node previous;
        }
    }

    public override void Run()
    {
        // [[3],[1,1],[2,2],[3,3],[4,4],[4],[3],[2],[1],[5,5],[1],[2],[3],[4],[5]]
        LRUCache cache = new(3);
        cache.Put(1, 1);
        cache.Put(2, 2);
        cache.Put(3, 3);
        cache.Put(4, 4);
        var a = cache.Get(4);
        a = cache.Get(3);
        a = cache.Get(2);
        a = cache.Get(1);
        cache.Put(5, 5);
        a = cache.Get(1);
        a = cache.Get(2);
        a = cache.Get(3);
        a = cache.Get(4);
        a = cache.Get(5);
    }
}