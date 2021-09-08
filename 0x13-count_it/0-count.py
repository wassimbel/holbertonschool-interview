#!/usr/bin/python3
import requests


def recursive_search(subreddit, word_list, titles, after=""):
    """ecursive function that queries the Reddit API, parses the title of all hot articles, and prints a sorted count
       of given keywords (case-insensitive, delimited by spaces """
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    header = {'User-Agent': 'Reddit API'}
  
    request = requests.get(url,
                       headers = header,
                       allow_redirects=False)

    if request.status_code != 200:
        return None
    if after is None:
        return titles

    for i in request.json().get('data').get('children'):
        title = i.get('data').get('title').split()
        for j in set(word_list):
            if j.lower() in [k.lower() for k in title]:
                if titles.get(j):
                    titles[j] += 1
                else:
                    titles[j] = 1

    after = request.json().get('data').get('after')
    recursive_search(subreddit, word_list, titles, after)
    return titles


def count_words(subreddit, word_list):
    """ calls the recursive_search and prints keywords """
    titles = recursive_search(subreddit, word_list, {})
    if titles:
        for i, j in sorted(titles.items(), key=lambda x: (-x[1], x[0])):
            if j != 0:
                print('{}: {}'.format(i, j))
