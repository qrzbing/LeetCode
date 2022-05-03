import requests
import json
import sys

session = requests.Session()
user_agent = r'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36'

question_list = {}


def get_problem_by_slug(slug):
    url = "https://leetcode.com/graphql"
    params = {'operationName': "getQuestionDetail",
              'variables': {'titleSlug': slug},
              'query': '''query getQuestionDetail($titleSlug: String!) {
            question(titleSlug: $titleSlug) {
                questionId
                questionFrontendId
                questionTitle
                questionTitleSlug
                content
                difficulty
                stats
                similarQuestions
                categoryTitle
                topicTags {
                        name
                        slug
                }
            }
        }'''
              }

    json_data = json.dumps(params).encode('utf8')

    headers = {'User-Agent': user_agent, 'Connection':
               'keep-alive', 'Content-Type': 'application/json',
               'Referer': 'https://leetcode-cn.com/problems/' + slug}
    resp = session.post(url, data=json_data, headers=headers, timeout=10)
    content = resp.json()

    # 题目详细信息
    question = content['data']['question']
    print(question)


def get_slug_by_id(id: int) -> str:
    url = "https://leetcode-cn.com/api/problems/all/"

    headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
    resp = session.get(url, headers=headers, timeout=10)

    question_list = json.loads(resp.content.decode('utf-8'))

    for question in question_list['stat_status_pairs']:
        # 题目编号
        question_id = question['stat']['question_id']
        # 题目名称
        question_slug = question['stat']['question__title_slug']
        # print(question_id)
        if str(question_id) == str(id):
            return question_slug
            # 题目状态
        question_status = question['status']

        # 题目难度级别，1 为简单，2 为中等，3 为困难
        level = question['difficulty']['level']

        # 是否为付费题目
        if question['paid_only']:
            continue
    return "problem not found"


# def get_problems():
#     url = "https://leetcode-cn.com/api/problems/all/"

#     headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
#     resp = session.get(url, headers=headers, timeout=10)

#     question_list = json.loads(resp.content.decode('utf-8'))
#     print(question_list)

#     for question in question_list['stat_status_pairs']:
#         # 题目编号
#         question_id = question['stat']['question_id']
#         # 题目名称
#         question_slug = question['stat']['question__title_slug']
#         # 题目状态
#         question_status = question['status']

#         # 题目难度级别，1 为简单，2 为中等，3 为困难
#         level = question['difficulty']['level']

#         # 是否为付费题目
#         if question['paid_only']:
#             continue



if __name__ == '__main__':
    get_problem_by_slug(get_slug_by_id(1984))
