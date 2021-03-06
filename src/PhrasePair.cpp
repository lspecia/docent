/*
 *  PhrasePair.cpp
 *
 *  Copyright 2012 by Christian Hardmeier. All rights reserved.
 *
 *  This file is part of Docent, a document-level decoder for phrase-based
 *  statistical machine translation.
 *
 *  Docent is free software: you can redistribute it and/or modify it under the
 *  terms of the GNU General Public License as published by the Free Software
 *  Foundation, either version 3 of the License, or (at your option) any later
 *  version.
 *
 *  Docent is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along with
 *  Docent. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Docent.h"
#include "PhrasePair.h"
#include "PhraseTable.h"

#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>

#include <sstream>

bool PhrasePairData::operator==(const PhrasePairData &o) const {
	return	phraseTable_ == o.phraseTable_ &&
			coverage_ == o.coverage_ &&
			sourcePhrase_ == o.sourcePhrase_ &&
			targetPhrase_ == o.targetPhrase_;
}

std::size_t hash_value(const PhrasePairData &p) {
	std::size_t seed = 0;
	boost::hash_combine(seed, p.phraseTable_);
	boost::hash_combine(seed, p.coverage_);
	boost::hash_combine(seed, p.sourcePhrase_.get());
	boost::hash_combine(seed, p.targetPhrase_.get());

	return seed;
}

WordAlignment::WordAlignment(uint nsrc, uint ntgt, const std::string &alignment) :
		nsrc_(nsrc), ntgt_(ntgt), matrix_(nsrc * ntgt) {
	std::istringstream is(boost::trim_copy(alignment));
	for(;;) {
		std::string ss, st;
		getline(is, ss, '-');
		getline(is, st, ' ');
		if(!is)
			break;

		uint s = boost::lexical_cast<uint>(ss);
		uint t = boost::lexical_cast<uint>(st);
		setLink(s, t);
	}
}
