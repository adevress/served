/*
 * Copyright (C) 2014 MediaSift Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SERVED_REQUEST_PARSER_IMPL_HPP
#define SERVED_REQUEST_PARSER_IMPL_HPP

#include <served/request_parser.hpp>
#include <served/request.hpp>

namespace served {

class request_parser_impl : public served::request_parser {
	request & d_request;

public:
	request_parser_impl(request & req)
		: served::request_parser()
		, d_request(req)
	{}

	std::tuple<request_parser::status, size_t> parse(const char *data, size_t len);

protected:
	virtual void http_field(const char *data, const char *field, size_t flen,
		const char *value, size_t vlen) override;

	virtual void request_method(const char *data, const char *at,
		size_t length) override;

	virtual void request_uri(const char *data, const char *at,
		size_t length) override;

	virtual void fragment(const char *data, const char *at,
		size_t length) override;

	virtual void request_path(const char *data, const char *at,
		size_t length) override;

	virtual void query_string(const char *data, const char *at,
		size_t length) override;

	virtual void http_version(const char *data, const char *at,
		size_t length) override;

	virtual void header_done(const char *data, const char *at,
		size_t length) override;
};

} // served namespace

#endif // SERVED_REQUEST_PARSER_IMPL_HPP